package Daliy1;

//experiment_4_2
import java.util.Random;
import java.util.Date;
import java.text.SimpleDateFormat;
public class experiment_4_2
{
    public static void main(String[] args){
        Shape[] shape=new Shape[20];
        for(int i=0;i<shape.length;i++)
        shape[i]=new Shape();
        Initialize(shape);
        System.out.println("遍历初始化后的原数组对象");
        GetArr(shape);
        System.out.println();
        ShapeComL scl=new ShapeComL();
        shape=scl.comparator(shape);
        System.out.println("遍历按照周长从小到大排序后的数组对象");
        GetArr(shape);
        System.out.println();
        ShapeComS scs=new ShapeComS();
        shape=scs.comparator(shape);
        System.out.println("遍历按照面积从小到大排序后的数组对象");
        GetArr(shape);
        System.out.println("软件工程21-8_2104060804_冯雪岩");
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		System.out.println(df.format(new Date()));
    }
    public static void Initialize(Shape[] shape){
        Random r=new Random();
        for(int i=0;i<shape.length;i++){
            double l=r.nextDouble(21.0)+1.6;
            double s=r.nextDouble(15)+9.7;
            if(i<5)
            shape[i].Set(l,s,"正方形"+(i+1));
            else if(i>=5&&i<10)
            shape[i].Set(l,s,"圆形"+(i+(-4)));
            else if(i>=10&&i<15)
            shape[i].Set(l,s,"三角形"+(i+(-9)));
            else if(i>=15&&i<20)
            shape[i].Set(l,s,"长方形"+(i+(-14)));
        }
    }
    public static void GetArr(Shape[] shape){
        for(int i=0;i<shape.length;i++){
            double l0=shape[i].getL();
            double s0=shape[i].getS();
            System.out.println("周长："+String.format("%.2f",l0)+"   "+"面积:"+String.format("%.2f",s0)+"   "+"编号："+shape[i].getName());
        }
    }

}
interface Comparator{
    public Shape[] comparator(Shape[] se);
}
//存放数据类
class Shape{
    private double l;
    private double s;
    private String Name;

    public Shape(){
        this.l=0;
        this.s=0;
        this.Name="null";
    }

    public void Set(double l, double s, String Name) {
        this.l = l;
        this.s = s;
        this.Name = Name;
    }

    public double getL() {
        return l;
    }

    public void setL(double l) {
        this.l = l;
    }


    public double getS() {
        return s;
    }


    public void setS(double s) {
        this.s = s;
    }


    public String getName() {
        return Name;
    }


    public void setName(String Name) {
        this.Name = Name;
    }

}
class ShapeComL implements Comparator{
    @Override
    public Shape[] comparator(Shape[] se){
        Shape temp=new Shape();
        for(int i=0;i<se.length-1;i++){
            for(int j=0;j<se.length-1-i;j++){
                if(se[j].getL()>se[j+1].getL()){
                   temp=se[j];
                   se[j]=se[j+1];
                   se[j+1]=temp;
                }
            }
        }
        return se;
    }
}
//面积排序的实现类
class ShapeComS implements Comparator{
    @Override
    public Shape[] comparator(Shape[] se){
        Shape temp=new Shape();
        for(int i=0;i<se.length-1;i++){
            for(int j=0;j<se.length-1-i;j++){
                if(se[j].getS()>se[j+1].getS()){
                    temp=se[j];
                    se[j]=se[j+1];
                    se[j+1]=temp;
                }
            }
        }
        return se;
    }
}
