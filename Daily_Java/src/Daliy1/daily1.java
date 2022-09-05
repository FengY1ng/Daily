package Daliy1;

public class daily1 {
	public static void main(String[] args) {
		String greeting="this is ";
		int n=greeting.length();
		int length=greeting.codePointCount(0, greeting.length());
		System.out.println(n);
		System.out.println(length);
	}
}
