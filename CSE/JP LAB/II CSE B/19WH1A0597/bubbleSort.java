import java.io.* ;
import java.util.Scanner;

public class bubbleSort {
	public static void main(String[] args) {
		int arr[], n, i, swapcount;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter array size: ");
		n = sc.nextInt();
		arr = new int[n];
		System.out.println("Enter array elements: ");
		for(i=0;i<n;i++) {
			arr[i] = sc.nextInt();
		}
		swapcount = bubblesort(arr, n);
		System.out.println("Elements after sorting: ");
		for(i=0;i<n;i++) {
			System.out.print(arr[i] + "	" );
		}
	}


	static int bubblesort( int arr[], int n) {
		int swapcount = 0, i, j, t;
		for(i=0;i<n;i++) {
			for(j=0; j<n-i-1;j++) {
				if(arr[j] > arr[j+1]) {
					t = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = t;
					swapcount += 1;
				}
			}
		}
		return swapcount;
	}
}