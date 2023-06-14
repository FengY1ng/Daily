#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

int BUFFER_SIZE = 10;  // 缓冲区大小

std::mutex mtx;  // 互斥锁
std::condition_variable producer_cv, consumer_cv;  // 条件变量

std::vector<int> buffer;  // 缓冲区
int producerIndex = 0;  // 生产者索引
int consumerIndex = 0;  // 消费者索引

class Monitor {
public:
    void produce(int item) {
        std::unique_lock<std::mutex> lock(mtx);

        // 如果缓冲区满了，等待消费者消费
        while (buffer.size() == BUFFER_SIZE) {
            producer_cv.wait(lock);
        }

        buffer.push_back(item);
        std::cout << "生产者生产了：" << item << std::endl;

        // 唤醒一个消费者进行消费
        consumer_cv.notify_one();
    }

    int consume() {
        std::unique_lock<std::mutex> lock(mtx);

        // 如果缓冲区为空，等待生产者生产
        while (buffer.empty()) {
            consumer_cv.wait(lock);
        }

        int item = buffer[consumerIndex];
        buffer.erase(buffer.begin() + consumerIndex);
        std::cout << "消费者消费了：" << item << std::endl;

        // 更新消费者索引
        consumerIndex = (consumerIndex + 1) % BUFFER_SIZE;

        // 唤醒一个生产者进行生产
        producer_cv.notify_one();

        return item;
    }
};

void producer(Monitor& monitor, int id) {
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));  // 模拟生产过程

        int item = id * 10 + i;  // 生产的物品
        monitor.produce(item);
    }
}

void consumer(Monitor& monitor, int id) {
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));  // 模拟消费过程

        int item = monitor.consume();
    }
}

int main() {
    int numProducers, numConsumers;
    std::cout << "请输入生产者数目：";
    std::cin >> numProducers;
    std::cout << "请输入缓冲区数目：";
    std::cin >> BUFFER_SIZE;
    std::cout << "请输入消费者数目：";
    std::cin >> numConsumers;

    Monitor monitor;

    std::vector<std::thread> producerThreads;
    std::vector<std::thread> consumerThreads;

    // 创建生产者线程
    for (int i = 0; i < numProducers; i++) {
        producerThreads.emplace_back(producer, std::ref(monitor), i);
    }

    // 创建消费者线程
    for (int i = 0; i < numConsumers; i++) {
        consumerThreads.emplace_back(consumer, std::ref(monitor), i);
    }

    // 等待所有线程完成
    for (auto& thread : producerThreads) {
        thread.join();
    }
    for (auto& thread : consumerThreads) {
        thread.join();
    }

    return 0;
}
