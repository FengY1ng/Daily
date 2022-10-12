package Daliy1;

//task2.java
import java.util.Scanner;
import java.util.Date;
import java.text.SimpleDateFormat;

abstract class Shape{
    public abstract double CalculatePerimeter();
    public abstract double CalculateArea();
}

class Circle extends Shape{
    private double range;
    public static final double PI=3.1415926;

    public Circle(){
        this.range=-1;
    }

    public Circle(double range){
        this.range=range;
    }

    @Override
    public double CalculatePerimeter(){
        return 2.0*PI*this.range;
    }

    @Override
    public double CalculateArea(){
        return PI*this.range*this.range;
    }
}

class Triangle extends Shape{
    private double l1,l2,l3;

    public Triangle(double l1,double l2,double l3){
        if(l1+l2>l3 && l2+l3>l1 &&l1+l3>l2){
            this.l1=l1;
            this.l2=l2;
            this.l3=l3;
        }
        else{
            System.out.println("Error!\n三条边的长度无法构成三角形!");
            this.l1=this.l2=this.l3=-1;
        }
    }

    @Override
    public double CalculatePerimeter(){
        return l1+l2+l3;
    }

    @Override
    public double CalculateArea(){
        double median=(l1+l2+l3)/2.0;
        return Math.pow(median*(median-l1)*(median-l2)*(median-l3),0.5);
    }
}

class Rectangle extends Shape{
    protected double length;
    protected double width;

    public Rectangle(){
        this.width=-1;
        this.length=-1;
    }

    public Rectangle(double length,double width){
        this.length=length;
        this.width=width;
    }

    @Override
    public double CalculatePerimeter(){
        return this.length*2.0+this.width*2.0;
    }

    @Override
    public double CalculateArea(){
        return this.length*this.width;
    }
}

class Square extends Rectangle{
    public Square(){
        this.length=-1;
        this.width=-1;
    }
    public Square(double length){
        this.length=length;
        this.width=length;
    }
}



public class task2 {
    public static void main(String[] args){
        Scanner cin=new Scanner(System.in);
        while(true){
            System.out.println("请按下想要进行的操作对应的序号");
            System.out.println("1.圆形");
            System.out.println("2.三角形");
            System.out.println("3.长方形");
            System.out.println("4.正方形");
            System.out.println("5.结束程序");
            int median=cin.nextInt();
            switch(median){
            case 1:
                ChooseCircle();
                break;
            case 2:
                ChooseTriangle();
                break;
            case 3:
                ChooseRectangle();
                break;
            case 4:
                ChooseSquare();
                break;
            case 5:
                System.out.println("软件工程21-8_2104060804_冯雪岩");
                SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                System.out.println(df.format(new Date()));
                cin.close();
                System.exit(0);
            }
        }
    }

    public static void ChooseCircle(){
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入半径");
        double r = sc.nextDouble();
        Circle cir = new Circle(r);
        double s = cir.CalculateArea();
        double c = cir.CalculatePerimeter();
        System.out.println("面积为：" + String.format("%.2f", s));
        System.out.println("周长为：" + String.format("%.2f", c));
    }
    public static void ChooseTriangle(){
        Scanner cin=new Scanner(System.in);
        System.out.print("请依次输入三角形的三条边长:");
        double l1=cin.nextDouble();
        cin.nextLine();
        double l2=cin.nextDouble();
        cin.nextLine();
        double l3=cin.nextDouble();
        cin.nextLine();
        Triangle triangle=new Triangle(l1,l2,l3);
        System.out.println("该三角形的周长为："+triangle.CalculatePerimeter());
        System.out.println("该三角形的面积为"+triangle.CalculateArea());
    }

    public static void ChooseRectangle(){
        Scanner cin=new Scanner(System.in);
        System.out.print("请依次输入矩形形的长和宽:");
        double length=cin.nextDouble(),width=cin.nextDouble();
        Rectangle rectangle=new Rectangle(length,width);
        System.out.println("该矩形的周长为："+rectangle.CalculatePerimeter());
        System.out.println("该矩形的面积为"+rectangle.CalculateArea());
    }

    public static void ChooseSquare(){
        Scanner cin=new Scanner(System.in);
        System.out.print("请输入正方形形的边长:");
        double length=cin.nextDouble();
        Square square=new Square(length);
        System.out.println("该正方形的周长为："+square.CalculatePerimeter());
        System.out.println("该正方形的面积为"+square.CalculateArea());
    }
}

