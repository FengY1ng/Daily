package Daliy1;

import java.util.Scanner;

public class experiment_1_2 {
    static int End=100;

    

    public static void main(String[] args){
        public class Accumulate{
            private int count=0;
            public int count(int num){
                if(num==0){
                    return 0;
                }
                if(num==1){
                    return 1;
                }
                return count(num-1)+count(num-2);
            }
            public Accumulate(int num){
                this.count=count(num);
            }
            public void printCount(){
                System.out.println("递归运算的结果为:"+count);
            }
        }
        int sumFor=0,sumWhile=0;
        Accumulate sumAccumulate=new Accumulate(End);

        //while
        int median=End;
        while(median!=0){
            sumWhile+=median;
            median--;
        }
        System.out.println("while循环的运算结果为:"+sumWhile);
        //for
        for(int i=End;i!=0;i--){
            sumFor+=i;
        }
        System.out.println("for循环的运算结果为:"+sumFor);
        //递归
        sumAccumulate.printCount();
    }
}
