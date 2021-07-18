import java.io.*;
import java.util.Scanner;

public class prime{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number:");
        int num = sc.nextInt();
        int p=0;
        for(int i=1;i<=num;i++){
            if(num % i == 0){
                p++;
            }
        }
        if(p==2){
            System.out.println(num + " is a prime number");
        }
        else{
            System.out.println(num + " is not a prime number");
        }
    }
}
