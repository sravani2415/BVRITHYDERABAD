import java.io.*;
import java.lang.String;
public class allFileNames{
	public static void main(String[] args){
		try
		{
			File myObj = new File("/home/sumanasri/Documents");
			subFiles(myObj);
		}
		catch(Exception e)
		{
		}
	}
	private static void subFiles(File myObj)
	{
		File[] subdir = myObj.listFiles();
		int i;
		for(i = 0; i<subdir.length; i++){
			if(subdir[i].isDirectory())
			{
				System.out.println(":: "+subdir[i].getName());
				subFiles(subdir[i]);
			}
			if(subdir[i].isFile()){
				System.out.println(subdir[i].getName());
			}
		}
}
}
