#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

int BUFFER_SIZE = 10;  // ��������С

std::mutex mtx;  // ������
std::condition_variable producer_cv, consumer_cv;  // ��������

std::vector<int> buffer;  // ������
int producerIndex = 0;  // ����������
int consumerIndex = 0;  // ����������

class Monitor {
public:
    void produce(int item) {
        std::unique_lock<std::mutex> lock(mtx);

        // ������������ˣ��ȴ�����������
        while (buffer.size() == BUFFER_SIZE) {
            producer_cv.wait(lock);
        }

        buffer.push_back(item);
        std::cout << "�����������ˣ�" << item << std::endl;

        // ����һ�������߽�������
        consumer_cv.notify_one();
    }

    int consume() {
        std::unique_lock<std::mutex> lock(mtx);

        // ���������Ϊ�գ��ȴ�����������
        while (buffer.empty()) {
            consumer_cv.wait(lock);
        }

        int item = buffer[consumerIndex];
        buffer.erase(buffer.begin() + consumerIndex);
        std::cout << "�����������ˣ�" << item << std::endl;

        // ��������������
        consumerIndex = (consumerIndex + 1) % BUFFER_SIZE;

        // ����һ�������߽�������
        producer_cv.notify_one();

        return item;
    }
};

void producer(Monitor& monitor, int id) {
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));  // ģ����������

        int item = id * 10 + i;  // ��������Ʒ
        monitor.produce(item);
    }
}

void consumer(Monitor& monitor, int id) {
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));  // ģ�����ѹ���

        int item = monitor.consume();
    }
}

int main() {
    int numProducers, numConsumers;
    std::cout << "��������������Ŀ��";
    std::cin >> numProducers;
    std::cout << "�����뻺������Ŀ��";
    std::cin >> BUFFER_SIZE;
    std::cout << "��������������Ŀ��";
    std::cin >> numConsumers;

    Monitor monitor;

    std::vector<std::thread> producerThreads;
    std::vector<std::thread> consumerThreads;

    // �����������߳�
    for (int i = 0; i < numProducers; i++) {
        producerThreads.emplace_back(producer, std::ref(monitor), i);
    }

    // �����������߳�
    for (int i = 0; i < numConsumers; i++) {
        consumerThreads.emplace_back(consumer, std::ref(monitor), i);
    }

    // �ȴ������߳����
    for (auto& thread : producerThreads) {
        thread.join();
    }
    for (auto& thread : consumerThreads) {
        thread.join();
    }

    return 0;
}
