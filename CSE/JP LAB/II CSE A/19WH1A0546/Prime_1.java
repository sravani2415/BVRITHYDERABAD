import java.io.*;
import java.util.Scanner;

public class Prime_1 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n;
		System.out.print("Enter a no: ");
		n = sc.nextInt();
		boolean flag = false;
		for(int i = 2 ; i <= n/2 ; i++) {
			if (n % i == 0) {
				flag = true;
			}
		}
		
		if (flag == false) {
			System.out.println(n+" is a prime no.");
		}
		else {
			System.out.println(n+" is not a prime no.");
		}
	}
}
