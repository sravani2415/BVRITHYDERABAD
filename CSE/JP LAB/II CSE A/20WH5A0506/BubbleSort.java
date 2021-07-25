C:\Users\hi\OneDrive
import java.util.Scanner;
public class BubbleSort {

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);
		int size, count = 0;
		//Reading size of the list

		System.out.print( "Enter the list size:20WH5A0506\n  ");
		size = read.nextInt();
		
		//Creating list with elements
		int list[] = new int[size];
		System.out.println("Enter any " + size + " integer numbers: ");
		for(int i = 0; i < size; i++)
			list[i] = read.nextInt();
		// Bubble sort logic
		int temp=0;
		for(int i=0;i<size-1;i++) {
			for(int j=0;j<size-i-1;j++) {
				if(list[j]<list[j+1]) {
					temp=list[j];
					list[j]=list[j+1];
					list[j+1]=temp;
					count++;
				}
			}	
		}
		
		// Displaying sorted list
		System.out.println("List of sorted elements: ");
		for(int x:list) {
			System.out.print(x + "   ");
		}
		System.out.println("\nTotal number of Interchanges is " + count);
	}
}