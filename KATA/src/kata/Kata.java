package kata;

import java.util.Scanner;

public class Kata {
	
	String userEntered = "";
	static int lengthOf_OriginalString = 0;
	static String reversedString = "";
	
	public Kata(){
		
	}
	
	public void userEnteredString() {
		Scanner inpScanner = new Scanner(System.in);
		System.out.println("Enter String to Reverse :");
		userEntered = inpScanner.nextLine();
	}
	
	public void printTheString() {
		System.out.println("Original String :" + userEntered);
		System.out.println("Reversed String :" + reversedString);
	}
	
	public static String solution(String str) {
		
		int lengthOf_OriginalString = 0;
		String reversedString = "";
		
		lengthOf_OriginalString = str.length();
		for(int i=lengthOf_OriginalString-1;i>=0;i--) {
			char j = str.charAt(i);
			reversedString = reversedString + Character.toString(j);
		}
		return reversedString;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
//		Kata rs = new Kata();
	//	rs.userEnteredString();
		//reversedString = Kata.solution(rs.userEntered);
		Kata.solution("world");
		System.out.println(reversedString);
		//rs.printTheString();
	}
}
 