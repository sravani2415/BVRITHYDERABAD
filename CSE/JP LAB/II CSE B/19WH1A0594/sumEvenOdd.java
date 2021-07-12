import java.io.* ;
import java.util.Scanner;

public class sumEvenOdd {
	public static void main(String[] args) {
		int n, i, sum_even = 0, sum_odd = 0;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter array size: ");
		n = sc.nextInt();
		int []arr = new int[n];
		System.out.println("Enter array elements: ");
		for(i=0;i<n;i++) {
			arr[i] = sc.nextInt();
		}
		for(i=0;i<n;i++) {
			if(arr[i] % 2 == 0) {
				sum_even = sum_even + arr[i];
			}
			else {
				sum_odd = sum_odd + arr[i];
			}
		}
		System.out.println("Even integers sum = " +sum_even);	
		System.out.println("Odd integers sum = " +sum_odd);
	}	
}