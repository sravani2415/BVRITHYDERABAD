import java.util.Scanner;

public class bubbleSort
{
	public static void main(String[] args){
		System.out.println("Enter the number of elements needed to be sorted");
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int a[] = new int[n];
		System.out.println("Enter the elements");
		for(int i=0;i<n;i++){
			a[i] = s.nextInt();
		}
		int temp, noc = 0;
		for(int i=0;i<n - 1;i++){
			for(int j =0; j<n-i-1; j++){
				if(a[j] < a[j+1]){
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
				noc++;
			}
		}
		System.out.println("After Bubble Sort ");
		for(int i=0;i<n;i++){
			System.out.print(a[i] + " ");
		}
		System.out.println("\nNumber of comparisions are" + " " + noc);
	}
}