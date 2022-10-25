package Daliy1;

import java.util.Date;
import java.text.SimpleDateFormat;

class ThreadTest extends Thread{
    public int sum=10;
    String lock=new String();
    @Override
    public void run(){
        while(sum>=0){
            synchronized(lock){
                System.out.println("sum="+sum--);
            }
        }
    }
}

public class experiment_5_2 {
    public static void main(String[] args)throws Exception{
        ThreadTest intThread=new ThreadTest();
        Thread intThread01=new Thread(intThread);
        Thread intThread02=new Thread(intThread);
        intThread01.start();
        intThread02.start();
        Thread.sleep(1000);
        System.out.println("软件工程21-8_2104060804_冯雪岩");
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		System.out.println(df.format(new Date()));
    }
}
