import java.util.Scanner;

class Main {
	private static class Plot {
		public int x;
		public int y;
		public int width;
		public int length;
		public int price;
		
		public String toString() {
			return "{x: " + x + ", y: " + y + ", width: " + width + ", length: " + length + ", price: " + price + "}";
		}
	}
	
	private static class TestCase {
		public int width;
		public int length;
		public int money;
		public int plotNum;
		public Plot plots[];
		
		public String toString() {
			String plotsStr = "[\n";
			for (int i = 0; i < plots.length; i++) {
				String suffix = i == plots.length - 1 ? "" : ", ";
				plotsStr += plots[i].toString() + suffix;
			}
			plotsStr += "\n]\n";
			
			return "width: " + width + ", length: " + length + ", money: " + money + ", plotNum: " + plotsStr;
		}
	}
	
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("How many test cases: ");
		int caseNum = scanner.nextInt();
		TestCase tests[] = getTestCases(caseNum, scanner);
		for (int i = 0; i < caseNum; i++) {
			System.out.println(" - " + tests[i].toString());
		}
		
		
	}
	
	public static TestCase[] getTestCases(int caseNum, Scanner scanner) {
		System.out.println("--------------------");
		TestCase tests[] = new TestCase[caseNum];
		for (int i = 0; i < caseNum; i++) {
			tests[i] = new TestCase();
			System.out.println("Test case" + i + " : ");
			System.out.println("width: ");
			tests[i].width = scanner.nextInt();
			System.out.println("length: ");
			tests[i].length = scanner.nextInt();
			System.out.println("money: ");
			tests[i].money = scanner.nextInt();
			System.out.println("how many plots: ");
			tests[i].plotNum = scanner.nextInt();
			tests[i].plots = new Plot[tests[i].plotNum];
			for (int j = 0; j < tests[i].plotNum; j++) {
				System.out.println("--------------------");
				System.out.println("x: ");
				tests[i].plots[j] = new Plot();
				int x = scanner.nextInt();
				tests[i].plots[j].x = x;
				System.out.println("y: ");
				int y = scanner.nextInt();
				tests[i].plots[j].y = y;
				System.out.println("width: ");
				int width = scanner.nextInt();
				tests[i].plots[j].width = width;
				System.out.println("length: ");
				int length = scanner.nextInt();
				tests[i].plots[j].length = length;
				System.out.println("price: ");
				int price = scanner.nextInt();
				tests[i].plots[j].price = price;
			}
		}
		return tests;
	}
}