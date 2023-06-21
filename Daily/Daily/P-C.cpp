#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

class Monitor {
private:
    std::mutex mutex;
    std::condition_variable producer_cv;
    std::condition_variable consumer_cv;
    std::vector<int> buffer;
    int bufferSize;

public:
    Monitor(int bufferSize) : bufferSize(bufferSize) {}

    void produce(int item) {
        std::unique_lock<std::mutex> lock(mutex);

        // 检查缓冲区是否已满
        if (buffer.size() >= bufferSize) {
            // 等待条件变量的信号，直到缓冲区非满
            producer_cv.wait(lock, [this] { return buffer.size() < bufferSize; });
        }

        // 将物品放入缓冲区
        buffer.push_back(item);

        std::cout << "生产者生产了: " << item << std::endl;

        // 通知消费者线程缓冲区非空
        consumer_cv.notify_one();
    }

    void consume() {
        std::unique_lock<std::mutex> lock(mutex);

        // 检查缓冲区是否为空
        if (buffer.empty()) {
            // 等待条件变量的信号，直到缓冲区非空
            consumer_cv.wait(lock, [this] { return !buffer.empty(); });
        }

        // 从缓冲区中取出物品进行消费
        int item = buffer.back();
        buffer.pop_back();

        std::cout << "消费者消费了: " << item << std::endl;

        // 通知生产者线程缓冲区非满
        producer_cv.notify_one();
    }
};

void producer(Monitor& monitor, int id) {
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        monitor.produce(id * 10 + i);
    }
}

void consumer(Monitor& monitor, int id) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        monitor.consume();
    }
}

int main() {
    int numProducers, numBuffers, numConsumers;

    std::cout << "请输入生产数目: ";
    std::cin >> numProducers;

    std::cout << "请输入缓冲区数目: ";
    std::cin >> numBuffers;

    std::cout << "请输入消费者数目: ";
    std::cin >> numConsumers;

    Monitor monitor(numBuffers);

    std::vector<std::thread> producerThreads;
    std::vector<std::thread> consumerThreads;

    for (int i = 0; i < numProducers; ++i) {
        producerThreads.emplace_back(producer, std::ref(monitor), i);
    }

    for (int i = 0; i < numConsumers; ++i) {
        consumerThreads.emplace_back(consumer, std::ref(monitor), i);
    }

    for (auto& thread : producerThreads) {
        thread.join();
    }

    for (auto& thread : consumerThreads) {
        thread.join();
    }

    return 0;
}
