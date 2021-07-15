import java.util.Scanner;
public class SumOfOddEven
{
	public static void main(String[] args)
	{
		int n, esum = 0, osum = 0;
		Scanner s = new Scanner(System.in);
		System.out.print("enter no. of elements: ");
		n = s.nextInt();
		int[] a = new int[n];
		System.out.println("enter the integers:");
		for(int i = 0; i < n; i++)
			a[i] = s.nextInt();
		for(int i = 0; i < n; i++)
		{
			if(a[i] % 2 == 0)
				esum = esum + a[i];
			else
				osum = osum + a[i];
		}
		System.out.println("sum of even integers: " + esum);
		System.out.println("sum of odd integers: " + osum);
	}
} 