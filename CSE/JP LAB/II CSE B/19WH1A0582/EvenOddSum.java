import java.util.Scanner;

public class EvenOddSum
{
	public static void main(String[] args){
		System.out.println("Enter the number of elements");
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int a[] = new int[n];
		System.out.println("Enter the elements");
		for(int i=0;i<n;i++){
			a[i] = s.nextInt();
		}
		int s_even = 0, s_odd = 0;
		for(int i=0;i<n;i++){
			if(a[i]%2 == 0)
			s_even += a[i];
			else
			s_odd += a[i];
		}
		System.out.println("Sum of odd numbers is " + s_odd +"\nSum of even numbers is " + s_even);
	}
}
