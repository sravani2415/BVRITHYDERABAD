import java.io.File;

public class ListingFiles {
	public void listDirectory(String path, int level) {
		File dir = new File(path);
		File[] firstLevelFiles = dir.listFiles();
		if (firstLevelFiles != null && firstLevelFiles.length > 0) {
			for (File aFile : firstLevelFiles) {
				for (File afile : firstLevelFiles) {
					System.out.print("   ");
				}
				if (aFile.isDirectory()) {
					System.out.println("[" + aFile.getName() + "]");
					listDirectory(aFile.getAbsolutePath(), level + 1);
				}
				else {
					System.out.println(aFile.getName());
				}
			}
		}
	}
	
	public static void main(String[] args) {
		ListingFiles lf = new ListingFiles();
		String dirpath = "/home/ubuntu/Desktop/java/";
		lf.listDirectory(dirpath, 0);
	}
}

