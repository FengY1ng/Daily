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
        int j;
        if((heights.length/2)%2==0){
            for(int i=0;i<heights.length/2+1;i++){
                int max=i;
                for(j=i+1;j<heights.length;j++){
                    max=heights[j]>heights[max]?j:max;
                }
                double t=heights[i];
                heights[i]=heights[max];
                heights[max]=t;
            }
            int k=heights.length/2-1;
            median=(heights[k]+heights[k+1])/2.0;
            return median;
        }
        else{
            for(int i=0;i<heights.length/2-1;i++){
                int max=i;
                for(j=i+1;j<heights.length;j++){
                    max=heights[j]>heights[max]?j:max;
                }
                double t=heights[i];
                heights[i]=heights[max];
                heights[max]=t;
            }
            median=heights[heights.length/2];
            return median;
        }
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
        System.out.println("最大值为："+Max(heights));
        System.out.println("最小值为："+Min(heights));
        System.out.println("平均值为："+Average(heights));
        System.out.println("中值为："+Median(heights));
    }
}
