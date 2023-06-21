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

        // ��黺�����Ƿ�����
        if (buffer.size() >= bufferSize) {
            // �ȴ������������źţ�ֱ������������
            producer_cv.wait(lock, [this] { return buffer.size() < bufferSize; });
        }

        // ����Ʒ���뻺����
        buffer.push_back(item);

        std::cout << "������������: " << item << std::endl;

        // ֪ͨ�������̻߳������ǿ�
        consumer_cv.notify_one();
    }

    void consume() {
        std::unique_lock<std::mutex> lock(mutex);

        // ��黺�����Ƿ�Ϊ��
        if (buffer.empty()) {
            // �ȴ������������źţ�ֱ���������ǿ�
            consumer_cv.wait(lock, [this] { return !buffer.empty(); });
        }

        // �ӻ�������ȡ����Ʒ��������
        int item = buffer.back();
        buffer.pop_back();

        std::cout << "������������: " << item << std::endl;

        // ֪ͨ�������̻߳���������
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

    std::cout << "������������Ŀ: ";
    std::cin >> numProducers;

    std::cout << "�����뻺������Ŀ: ";
    std::cin >> numBuffers;

    std::cout << "��������������Ŀ: ";
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
