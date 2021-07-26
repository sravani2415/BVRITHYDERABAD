import java.io.*;
import java.util.Scanner;

public class bubbleSort_15 {
	public static void main(String ars[]) {
		Scanner sc = new Scanner(System.in);
		int n;
		System.out.print("Enter no of elements: ");
		n = sc.nextInt();
		
		int numbers[] = new int[n];
		System.out.println("Enter nos. to be sorted: ");
		for(int i = 0 ; i < n ; i++ ) {
			numbers[i] = sc.nextInt();
		}
		
		int count = 0;
		for(int i = 0 ; i < n ; i++ ) {
			for(int j = 0 ; j < n-1-i ; j++) {
				if (numbers[j] < numbers[j+1]) {
					int temp = numbers[j];
					numbers[j] = numbers[j+1];
					numbers[j+1] = temp;
					count++;
				}
			}
		}
		System.out.println("Sorted Order");
		for(int i = 0 ; i < n ; i++) {
			System.out.print(numbers[i]+" ");
		}
	}
}