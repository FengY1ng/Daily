package Daliy1;

//PersonApp.java
import java.util.Scanner;
import java.util.Date;
import java.text.SimpleDateFormat;

class Person
{
    private String name;
    private int age;
    private char sex;
    public Person(String name,int age,char sex){
        this.name=name;
        this.age=age;
        this.sex=sex;
    }
    public String show(){
        return(name+" "+sex+" "+age+"岁");
    }
    public Person(){
        this.age=-1;
        this.name=null;
        this.sex=' ';
    }
    public String GetName(){
        return this.name;
    }
    public int GetAge(){
        return this.age;
    }
    public char GetSex(){
        return this.sex;
    }
}
class Student extends Person
{
    private int id;
    public Student(String name,int age,char sex,int id){
        super(name,age,sex);
        this.id=id;
    }

    @Override
    public String show(){
        return(GetName()+" "+GetSex()+" "+GetAge()+"岁 学号:"+this.id);
    }
}

class Teacher extends Person
{
    private String course;
    public Teacher(String name,int age,char sex,String course){
        super(name,age,sex);
        this.course=course;
    }
    @Override
    public String show(){
        return(GetName()+" "+GetSex()+" "+GetAge()+"岁 "+this.course);
    }
}

public class PersonApp {
    public static void main(String[] args){
        String name,course;
        int age,id;
        char sex;
        Scanner cin=new Scanner(System.in);
        System.out.println("请输入Person对象的姓名:");
        name=cin.next();
        System.out.println("请输入Person对象的年龄 ：");
        age=cin.nextInt();
        System.out.println("请输入Person对象的性别:");
        sex=cin.next().toCharArray()[0];
        Person person=new Person(name,age,sex);
        System.out.println("请输入Student对象的姓名:");
        name=cin.next();
        System.out.println("请输入Student对象的年龄 ：");
        age=cin.nextInt();
        System.out.println("请输入Student对象的性别");
        sex=cin.next().toCharArray()[0];
        System.out.println("请输入Student对象的学号:");
        id=cin.nextInt();
        Student student=new Student(name, age, sex, id);
        System.out.println("请输入Teacher对象的姓名:");
        name=cin.next();
        System.out.println("请输入Teacher对象的年龄 ：");
        age=cin.nextInt();
        System.out.println("请输入Teacher对象的性别");
        sex=cin.next().toCharArray()[0];
        System.out.println("请输入Teacher对象的课程名称:");
        course=cin.next();
        Teacher teacher=new Teacher(name, age, sex, course);
        System.out.println("Person对象:"+person.show());
        System.out.println("Student对象:"+student.show());
        System.out.println("Teacher对象:"+teacher.show());
        cin.close();
        System.out.println("软件工程21-8_2104060804_冯雪岩");
		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		System.out.println(df.format(new Date()));
    }
}
