package Daliy1;

import java.util.Scanner;

public class experiment_1_3 {

    //最大值
    public static double Max(double[] heights){
        double max=-1;
        for(int i=0;i<heights.length;i++){
            if(heights[i]>max){
                max=heights[i];
            }
        }
        return max;
    }
    //最小值
    public static double Min(double[] heights){
        double min=500;
        for(int i=0;i<heights.length;i++){
            if(heights[i]<min){
                min=heights[i];
            }
        }
        return min;
    }
    //平均值
    public static double Average(double[] heights){
        double average=0.0;
        for(int i=0;i<heights.length;i++){
            average+=heights[i];
        }
        average/=heights.length;
        return average;
    }
    //中值
    public static double Median(double[] heights){
        double median=-1;
        for(int i=0;i<heights.length;i++){

        }
        return median;
    }
    public static void main(String[] args){
        Scanner cin= new Scanner(System.in);
        int n;
        System.out.println("请输入人数:");
        n=cin.nextInt();
        double[] heights=new double[n];
        for(int i=0;i<n;i++){
            System.out.println("请输入第"+(i+1)+"个人的身高");
            heights[i]=cin.nextDouble();
        }


        cin.close();
    }
}
