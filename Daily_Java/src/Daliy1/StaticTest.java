package Daliy1;

public class StaticTest {
	public static void main(String[] args){
		Employee1 num1=new Employee1("张三",50000);
		num1.setId();
		Employee1 num2=new Employee1("李四",60000);
		num2.setId();
		System.out.println(num1.getId());
		System.out.println(num2.getId());
	}
}

class Employee1{
	private String name;
	private double salary;
	private static int nextId=1;
	private int id;
	public Employee1(String n,double s){
		name=n;
		salary=s;
	}
	public void setId(){
		id=nextId;
		nextId++;
	}
	public int getId(){
		return id;
	}
}
