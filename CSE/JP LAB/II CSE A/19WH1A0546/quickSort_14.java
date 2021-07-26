import java.io.*;
import java.util.Scanner;

public class quickSort_14 {
	String names[];
	public static void main(String args[]) {
		quickSort_14 qs = new quickSort_14();
		Scanner sc = new Scanner(System.in);
		
		int n;
		System.out.print("Enter no of elements: ");
		n = sc.nextInt();
		
		qs.names = new String[n];
		System.out.println("Enter elements: ");
		for(int i = 0 ; i < n ; i++) {
			qs.names[i] = sc.nextLine();
		}
		qs.sort(0, n-1);
		System.out.println("Sorted order: ");
		for(int i = 0 ; i < n ; i++) {
			System.out.println(qs.names[i]);
		}
	}
	
	void sort(int start, int end) {
		int s = start;
		int e = end;
		String pivot = names[start + (end - start) / 2];
		
		while(s <= e) {
			while (names[s].compareToIgnoreCase(pivot) < 0) {
				s++;
			}
			while(names[e].compareToIgnoreCase(pivot) > 0) {
				e++;
			}
			if (s <= e) {
				swap(s, e);
				s++;
				e--;
			}
		}
		if(start < e) {
			sort(start, e);
		}
		if (s < end) {
			sort(s, end);
		}
	}
	
	void swap(int i, int j) {
		String temp = names[i];
		names[i] = names[j];
		names[j] = temp;
	}
}