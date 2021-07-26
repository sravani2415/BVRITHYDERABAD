import java.io.*;
import java.util.*;
class strings_sorting{
        void sort(){
                Scanner s = new Scanner(System.in);
                System.out.println("Enter number of strings:");
                int n = s.nextInt();
                String[] str = new String[n];
                System.out.println("Enter the strings:");
                for(int i=0;i<n;i++){
                        str[i] = new String(s.next());
                }
                for(int i=0;i<n;i++){
                        for(int j=i+1;j<n;j++){
                                if(str[i].compareTo(str[j])>0){
                                        String temp = str[i];
                                        str[i] = str[j];
                                        str[j] = temp;
                                }
                        }
                }
                System.out.println("Sorted strings are:");
                for(int i=0;i<n;i++){
                        System.out.println(str[i]);
                }
        }
}
class Quick_Sort{
        public static void main(String[] args){
                strings_sorting obj = new strings_sorting();
                obj.sort();
        }
}