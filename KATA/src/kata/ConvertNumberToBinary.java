package kata;

import java.util.InputMismatchException;
import java.util.Scanner;
import kata.NotADecimalNumberException;

//	class ConvertNumberToBinary
public class ConvertNumberToBinary 
{

	int decNum = 0;
	int binNum = 0;
	int quo = 0;
	int rem = 0;
	boolean decNumGreater = true;

	//	method to get the decimal number from the user
	public void getNumberFromUser() throws NotADecimalNumberException {
		Scanner reader = new Scanner(System.in);
		try {
			System.out.println("Enter Number : ");		
			decNum = reader.nextInt();
			reader.close();
		} catch(InputMismatchException e) {
			throw new NotADecimalNumberException("Not A Decimal Number");
		}
		convertDecNumToBinNum(decNum);
		System.out.println();
	}

	// method to convert decNum to binNum
	public void convertDecNumToBinNum(int decNum) {

		for (; decNumGreater = true;) {
			// divide the number by 2 - to get the quotient
			quo = decNum / 2;
			// divide the number by 2 - to get the reminder
			rem = decNum % 2;
			// print the reminder
			System.out.print(rem);
			// assign the quotient to decNum
			decNum = quo;

			/*
			 * The exit condition is if the decimal number is less than 2.
			 */
			if (decNum > 2) {
				continue;
			} else {
				System.out.println(rem);
				decNumGreater = false;
				break;
			}
		} // for loop ends here
		return;
	} // convertDecNumToBinNum method ends here

	// main method
	public static void main(String[] args) {
		ConvertNumberToBinary bin = new ConvertNumberToBinary();
		// get the decimal number from the user
		try {
			bin.getNumberFromUser();
		} catch (NotADecimalNumberException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	} // main method ends here
} // class ends here
