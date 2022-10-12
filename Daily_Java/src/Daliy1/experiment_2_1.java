package Daliy1;

public class experiment_2_1{
    static double PI=3.141592657589793;

    //圆类
    static class Circle{
        private double range;

        public Circle(double range){
            this.range=range;
        }
        //获取半径
        public double GetRange(){
            return this.range;
        }
        //修改半径
        public void ChangeRange(double newRange){
            this.range=newRange;
        }
        //计算面积
        public double GetArea(){
            return PI*this.range*this.range;
        }
        //计算周长
        public double GetPerimeter(){
            return 2.0*PI*this.range;
        }
    }

    //圆柱类
    static class Cylinder{
        private Circle bottomCircle;
        private double height;

        public Cylinder(double range,double height){
            this.bottomCircle.range=range;
            this.height=height;
        }
        public Cylinder(Circle circle,double height){
            this.bottomCircle=circle;
            this.height=height;
        }
        //获取底圆半径
        public double GetBottomCircleRange(){
            return this.bottomCircle.range;
        }
        //修改底圆半径
        public void ChangeBottomCircleRange(double newRange){
            this.bottomCircle.range=newRange;
        }
        //计算表面积
        public double GetArea(){
            return 2.0*this.bottomCircle.GetArea()+this.height*this.bottomCircle.GetPerimeter();
        }
        //计算体积
        public double GetVolume(){
            return this.bottomCircle.GetArea()*this.height;
        }
    }
    public static void main(String[] args){
        Circle circle=new Circle(10);
        System.out.println("该圆的面积为:"+circle.GetArea());
        System.out.println("该圆的周长为:"+circle.GetPerimeter());
        Cylinder cylinder=new Cylinder(circle, 20);
        System.out.println("该圆柱的底圆半径为:"+cylinder.GetBottomCircleRange());
        System.out.println("该圆柱的表面积为:"+cylinder.GetArea());
        System.out.println("该圆柱的体积为:"+cylinder.GetVolume());
    }
}