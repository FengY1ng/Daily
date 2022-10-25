package Daliy1;

import java.io.IOException;
import java.util.Date;
import java.text.SimpleDateFormat;

class Thread3 extends Thread{
    int sum=10;
	public void run() {
		while(sum>=0){
				try {
					Thread.sleep(100);
				}catch(InterruptedException e) {
					e.printStackTrace();
				}
				System.out.println("sum="+sum--);
		}
	}
}

public class experiment_5_3 {
    public static void main(String[] args) throws IOException,InterruptedException{
        Thread3 test=new Thread3();
        Thread test01=new Thread(test);
        Thread test02=new Thread(test);
        Thread test03=new Thread(test);
        test01.start();
        test02.start();
        test03.start();
        Thread.sleep(100);
        test01.interrupt();
        test02.interrupt();
        test03.interrupt();
        Thread.sleep(10000);
        System.out.println("软件工程21-8_2104060804_冯雪岩");
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		System.out.println(df.format(new Date()));
    }
}
