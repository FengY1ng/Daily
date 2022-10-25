package Daliy1;

import java.util.Date;
import java.text.SimpleDateFormat;


class Counter{
    public static final Object lock=new Object();
    public static int count=0;
}

class Thread01 extends Thread{

    public Thread01(){
        System.out.println("新建线程Thread01");
    }

    @Override
    public void run(){
        System.out.println("Thread01线程运行");
        while(!interrupted()){
            System.out.println("Thread01 is running.");
        }
        if(!interrupted()){
            System.out.println("Thread01线程中断");
        }
        else{
            System.out.println("Thread01线程终止");
        }
    }
}

class Thread02 extends Thread{

    public Thread02(){
        System.out.println("新建线程Thread02");
    }

    @Override
    public void run(){
        System.out.println("Thread02线程运行");
        for(int i=0;i<2;i++){
            System.out.println("Thread02 is running.");
        }
        if(interrupted()){
            System.out.println("Thread02中止");
        }
        else{
            System.out.println("Thread02线程终止");
        }
    }
}

public class experiment_5_1 {
    public static void main(String[] args)throws Exception{
        Thread01 thread01=new Thread01();
        Thread02 thread02=new Thread02();
        thread01.start();
        thread02.start();
        thread01.interrupt();
        Thread.sleep(1000);
        System.out.println("软件工程21-8_2104060804_冯雪岩");
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		System.out.println(df.format(new Date()));
    }
}
