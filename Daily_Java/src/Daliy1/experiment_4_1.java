package Daliy1;

//experiment_4_1
import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.Scanner;
interface ShapeComparator{
    public int compareTo(Shape s1,Shape s2);
}

class PerimeterComparator implements ShapeComparator{
    PerimeterComparator(){}
    @Override
    public int compareTo(Shape s1,Shape s2)
    {
        if(s1.CalculatePerimeter()>s2.CalculatePerimeter()){
            return 1;
        }
        else if(s1.CalculateArea()<s2.CalculatePerimeter()){
            return -1;
        }
        else{
           return 0;
        }

    }
}
class AreaComparator implements ShapeComparator
{
    AreaComparator(){}
    @Override
    public int compareTo(Shape s1,Shape s2){
        if(s1.CalculateArea()>s2.CalculateArea()){
            return 1;
        }
        else if(s1.CalculateArea()<s2.CalculateArea()){
            return -1;
        }
        else{
            return 0;
        }
    }
}




public class experiment_4_1 {
    public static void main(String[] args){
        PerimeterComparator p=new PerimeterComparator();
        AreaComparator a=new AreaComparator();
        System.out.println("返回值有三种情况，大于0表示l1>l2,等于0表示l1=l2，小于0表示l1<l2，面积同理");
        Scanner cin=new Scanner(System.in);
        System.out.println("请选择两个想要进行操作图形对应的序号");
        System.out.println("1.圆形");
        System.out.println("2.三角形");
        System.out.println("3.长方形");
        System.out.println("4.正方形");
        int median1=cin.nextInt(),median2=cin.nextInt();
        Create(median1,median2);
        System.out.println("请输入圆的半径:");
        double range=cin.nextDouble();
        Circle circle=new Circle(range);
        System.out.println("请输入正方形的边长:");
        double length=cin.nextDouble();
        Square square=new Square(length);
        System.out.println("周长大小比较:"+p.compareTo(circle,square));
        System.out.println("面积大小比较:"+a.compareTo(circle, square));
        cin.close();
        System.out.println("软件工程21-8_2104060804_冯雪岩");
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		System.out.println(df.format(new Date()));
    }
    static Shape Create(int l1,int l2){
        if(l1==1 && l2==1){
            Shape circle=new Circle();
            return circle;
        }
        if(l1==2 && l2==1){
            Shape circle=new Circle();
            return circle;
        }
        else{
            Shape circle=new Circle();
            return circle;
        }
    }
}
