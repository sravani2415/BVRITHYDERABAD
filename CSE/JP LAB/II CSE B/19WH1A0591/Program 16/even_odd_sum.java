import java.util.*;
class even_odd_sum
{
	public static void main(String[] args)
	{
		int n,i,even_sum=0,odd_sum=0;
		Scanner input = new Scanner(System.in);
		n = input.nextInt();
		int x[] = new int[n];
		System.out.print("Enter the elements:");
		for(i=0;i<n;i++)
		{
			x[i] = input.nextInt();
		}
		for(i=0;i<n;i++)
		{
			if(x[i] % 2 == 0)
				even_sum = even_sum + x[i];
			else
				odd_sum = odd_sum + x[i];
		}
		System.out.println("Even Sum : " + even_sum);
		System.out.println("Odd Sum : " + odd_sum);
	}
}