//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <queue>
//
//using namespace std;
//
//mutex mtx; // �����ź���
//condition_variable cv; // ������������
//queue<int> waitingQueue; // �ȴ��Ĺ˿Ͷ���
//bool bSleeping = true; // ��ʦ�Ƿ�����˯��
//const int customerN = 15;//һ������customerN���˿���������
//const int chairN = 5;//һ������chairN������
//int nCustomerDone = 0;//�Ѿ�������Ĺ˿�����
//
//void Barber();  // ��ʦ�̺߳���
//void Customer(int); // �˿��̺߳���
//
//int main() {
//    thread tBarber(Barber); // ������ʦ�߳�
//
//    // ����N���˿��߳�
//    thread tCustomers[customerN];
//    for (int i = 0; i < customerN; i++) {
//        tCustomers[i] = thread(Customer, i);
//        this_thread::sleep_for(chrono::seconds(i/2+1));//ÿ��(�ڼ�λ�˿���/2)+1��ʱ���й˿�����
//    }
//
//    // �ȴ������߳̽���
//    tBarber.join();
//    for (int i = 0; i < customerN; i++) {
//        tCustomers[i].join();
//    }
//
//    return 0;
//}
//
//void Barber() {
//    while (true) {
//        unique_lock<mutex> lock(mtx);
//
//        // �ȴ��˿�
//        while (waitingQueue.empty()) {
//            bSleeping = true;
//            cout << "��ʦ����˯��" << endl;
//            cv.wait(lock);
//        }
//
//        // ȡ��һ���˿�
//        int customer = waitingQueue.front();
//        waitingQueue.pop();
//        cout << "��ʦ����Ϊ�˿� " << customer << " ��" << endl;
//
//        // �ͷŻ���������
//        lock.unlock();
//
//        // ˯��һ��ʱ��ģ��������
//        this_thread::sleep_for(chrono::seconds(8));
//
//        //��������ͳ���Ѿ����Ĺ˿�����
//        if (++nCustomerDone == customerN)
//        {
//            break;
//        }
//    }
//}
//
//void Customer(int i) {
//    unique_lock<mutex> lock(mtx);
//
//    // ������ӻ��п�λ����ô�����µȴ���
//    if (waitingQueue.size() < 5) {
//        waitingQueue.push(i);
//        cout << "�˿� " << i << " ���������ϵȴ����������л��� " << waitingQueue.size() << " ���˿�" << endl;
//
//        // ������ʦ
//        if (bSleeping) {
//            cout << "�˿� " << i << " ��������ʦ" << endl;
//            bSleeping = false;
//            cv.notify_one();
//        }
//    }
//    else {
//        // ������뿪,ͬʱ���������һ
//        cout << "�˿� " << i << " ����û��λ�������뿪��" << endl;
//        nCustomerDone++;
//    }
//}