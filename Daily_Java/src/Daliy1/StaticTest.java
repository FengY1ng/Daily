package Daliy1;

public class StaticTest {
	public static void main(String[] args){
		int i=7;
		System.out.println(i/2);
	}
}

class Employee1{

	private static int nextId=1;
	private int id;
	public Employee1(String n,double s){

	}
	public void setId(){
		id=nextId;
		nextId++;
	}
	public int getId(){
		return id;
	}
}
