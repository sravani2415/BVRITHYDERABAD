import java.util.Scanner;
public class Prime{
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		System.out.println("Enter a number");
		int n = s.nextInt();
		if(isPrime(n)){
			System.out.println(n + " is a prime number");
		}else
		{
			System.out.println(n + " is not a prime number");
		}
	}
	public static boolean isPrime(int n){
		int flag = 0;
		if(n<=1){
			return false;
		}
		for(int i=2;i<n;i++)
		{
			if(n%i==0){
				flag=1;
			}
		}
		if(flag==1){
			return false;
		}
		else{
			return true;
		}
	}
}
