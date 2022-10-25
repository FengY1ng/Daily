package Daliy1.Java_experiment_6;

import java.util.Date;
import java.text.SimpleDateFormat;

class ThreadBuy implements Runnable{
    private int num=5;
    String str=new String();
    @Override
    public void run(){
        while(num>0){
            synchronized(str){
                System.out.println("有"+(6-num)+"个人买到票了");
            }
            num--;
            try{
            Thread.sleep(1000);
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }
    }
}

public class experiment_6_1 {
    public static void main(String[] args){
        ThreadBuy buy=new ThreadBuy();
        Thread thread=new Thread(buy);
        thread.start();
        try{
            Thread.sleep(10000);
        }catch(InterruptedException e){
            e.printStackTrace();
        }
        System.out.println("软件工程21-8_2104060804_冯雪岩");
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		System.out.println(df.format(new Date()));
    }
}
