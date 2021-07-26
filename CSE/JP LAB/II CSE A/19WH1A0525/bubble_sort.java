import java.io.*;
import java.util.Scanner;
class bubble_sort{
        public static void main(String[] args){
               System.out.println("19wh1a0525 - Aradya");
               int num,i,j,temp;
               Scanner input = new Scanner(System.in);
               System.out.println("Enter number of elements:");
               num = input.nextInt();
               int array[] = new int[num];
               System.out.println("Enter elements:");
               for(i=0;i<num;i++){
                  array[i] = input.nextInt();
               }
               for(i=0;i<num-1;i++){
                 for(j=0;j<num-i-1;j++){
                     if(array[j]<array[j+1]){
                        temp = array[j];
                        array[j]=array[j+1];
                        array[j+1]=temp;
                     }
                  }
               }
               System.out.println("After sorting:");
               for(i=0;i<num;i++)
                   System.out.println(array[i]);
        }
}