import java.io.File;
import java.util.Scanner;

public class DirectoryList_13 {
	public void listDirectory(String dirPath, int level) {
		File dir = new File(dirPath);
		File[] firstLevelFiles = dir.listFiles();
		if (firstLevelFiles != null && firstLevelFiles.length > 0) {
			for (File aFile : firstLevelFiles) {
				for (int i = 0; i < level; i++) {
					System.out.print("\t");
				}
				if (aFile.isDirectory()) {
					System.out.println("[" + aFile.getName() + "]");
					listDirectory(aFile.getAbsolutePath(), level + 1);
				} else {
					System.out.println(aFile.getName());
				}
			}
		}
	}

	public static void main(String args[]) {
		DirectoryList_13 test = new DirectoryList_13();
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter address of a directory : ");
		String dirToList = sc.nextLine();
		test.listDirectory(dirToList, 0);
	}
}
