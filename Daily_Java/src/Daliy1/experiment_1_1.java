package Daliy1;

import java.util.Scanner;

public class experiment_1_1 {
	public static void main(String[] args) {
		Scanner cin=new Scanner(System.in);
		int num1,num2;
		System.out.println("请输入分子：");
		num1=cin.nextInt();
		while(true){
		System.out.println("请输入分母：");
		num2=cin.nextInt();
		if(num2!=0){
			break;
		}
		System.out.println("输入的分母为0,请重新输入!");
		}
		System.out.println("计算结果的商为:"+num1/num2+"余数为:"+num1%num2);
		cin.close();
	}
}
