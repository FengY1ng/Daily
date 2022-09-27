package Daliy1;

public class experiment_1_2 {
    static int End=100;

    public static int Accumulate(int n){
        int count=0;
        if(n==1){
            return 1;
        }
        if(n==0){
            return 0;
        }
        count=Accumulate(n-1)+n;
        return count;
    }

    public static void main(String[] args){
        int sumFor=0,sumWhile=0;

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
        System.out.println("递归的运算结果为:"+Accumulate(End));
    }
}
