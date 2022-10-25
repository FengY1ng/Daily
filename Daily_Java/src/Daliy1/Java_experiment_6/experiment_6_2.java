package Daliy1.Java_experiment_6;

import java.util.Date;
import java.text.SimpleDateFormat;

class ThreadUnite implements Runnable{
    Thread joinThreadMover;
    Thread joinThreadManager;

    public void setJoinThreadMover(Thread t) {
        joinThreadMover = t;
    }

    public void setJoinThreadManger(Thread t) {
        joinThreadManager = t;
    }
    static Object lock=new Object();
    @Override
    public void run() {
        if (Thread.currentThread().getName().equals("Thread01")) {
            try {
                System.out.println("Thread01等待Thread02执行...");
                joinThreadMover.start();
                joinThreadMover.join();
                System.out.println("Thread01执行完毕...");
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        } else if (Thread.currentThread().getName().equals("Thread02")) {
            try {
                System.out.println("Thread02等待Thread03执行...");
                joinThreadManager.start();
                joinThreadManager.join();
                System.out.println("Thread02执行完毕...");
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        } else if (Thread.currentThread().getName().equals("Thread03")) {
            System.out.println("Thread03开始执行...");
            System.out.println("Thread03执行完毕...");

        }
}
}

public class experiment_6_2 {
    public static void main(String[] args){
        System.out.println("软件工程21-8_2104060804_冯雪岩");
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		System.out.println(df.format(new Date()));
            ThreadUnite test1 = new ThreadUnite();
            Thread one = new Thread(test1);
            Thread two = new Thread(test1);
            Thread three = new Thread(test1);
            one.setName("Thread01");
            two.setName("Thread02");
            three.setName("Thread03");
            test1.setJoinThreadMover(two);
            test1.setJoinThreadManger(three);
            one.start();
    }
}
