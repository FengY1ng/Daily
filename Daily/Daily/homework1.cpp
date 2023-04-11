//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <queue>
//
//using namespace std;
//
//mutex mtx; // 互斥信号量
//condition_variable cv; // 条件变量对象
//queue<int> waitingQueue; // 等待的顾客队列
//bool bSleeping = true; // 理发师是否正在睡觉
//const int customerN = 15;//一共会有customerN个顾客来到理发店
//const int chairN = 5;//一共会有chairN把椅子
//int nCustomerDone = 0;//已经完成理发的顾客数量
//
//void Barber();  // 理发师线程函数
//void Customer(int); // 顾客线程函数
//
//int main() {
//    thread tBarber(Barber); // 创建理发师线程
//
//    // 创建N个顾客线程
//    thread tCustomers[customerN];
//    for (int i = 0; i < customerN; i++) {
//        tCustomers[i] = thread(Customer, i);
//        this_thread::sleep_for(chrono::seconds(i/2+1));//每隔(第几位顾客数/2)+1的时间有顾客来到
//    }
//
//    // 等待所有线程结束
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
//        // 等待顾客
//        while (waitingQueue.empty()) {
//            bSleeping = true;
//            cout << "理发师正在睡觉" << endl;
//            cv.wait(lock);
//        }
//
//        // 取出一个顾客
//        int customer = waitingQueue.front();
//        waitingQueue.pop();
//        cout << "理发师正在为顾客 " << customer << " 理发" << endl;
//
//        // 释放互斥量对象
//        lock.unlock();
//
//        // 睡眠一段时间模拟理发过程
//        this_thread::sleep_for(chrono::seconds(8));
//
//        //理发结束后统计已经理发的顾客数量
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
//    // 如果椅子还有空位，那么就坐下等待理发
//    if (waitingQueue.size() < 5) {
//        waitingQueue.push(i);
//        cout << "顾客 " << i << " 坐在椅子上等待理发，队列中还有 " << waitingQueue.size() << " 个顾客" << endl;
//
//        // 唤醒理发师
//        if (bSleeping) {
//            cout << "顾客 " << i << " 唤醒了理发师" << endl;
//            bSleeping = false;
//            cv.notify_one();
//        }
//    }
//    else {
//        // 否则就离开,同时完成人数加一
//        cout << "顾客 " << i << " 发现没有位置坐，离开了" << endl;
//        nCustomerDone++;
//    }
//}