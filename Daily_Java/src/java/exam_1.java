package java;

import java.util.Scanner;

public class exam_1 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int num[]=new int[10];
        for(int i=0;i<10;i++){
            num[i]=sc.nextInt();
        }
        for(int i=0;i<10;i++){
            int min=i;
            for(int j=i+1;j<10;j++){
                if(num[j]<num[min]){
                    min=j;
                }
            }
            int t=num[i];
            num[i]=num[min];
            num[min]=t;
        }
        for(int i=0;i<10;i++){
            System.out.println(num[i]);
        }
        sc.close();
    }
}
