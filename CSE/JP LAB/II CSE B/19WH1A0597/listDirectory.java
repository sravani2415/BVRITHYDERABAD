import java.io.File;

public class listDirectory {
	public void listdirectory(String dirPath, int level) {
		File dir = new File(dirPath);
		File[] firstLevelFiles = dir.listFiles();
		if (firstLevelFiles != null && firstLevelFiles.length > 0) {
			for (File aFile : firstLevelFiles) {
				for (int i = 0; i < level; i++) {
					System.out.print("\t");
				}
				if (aFile.isDirectory()) {
					System.out.println("[" + aFile.getName() + "]");
					listdirectory(aFile.getAbsolutePath(), level + 1);
				} else {
					System.out.println(aFile.getName());
				}
			}
		}
	}

	public static void main(String[] args) {
		listDirectory test = new listDirectory();
		// String dirToList ="C:\\javaLab";
		String dirToList ="D:\\Chandralekha\\2-2 Semester\\Business Economics and Financial Analysis";
		test.listdirectory(dirToList, 0);
	}
}

