import java.util.Scanner;
import java.util.ArrayDeque;

class Main {
	private static class Plot {
		public int id;
		public int x;
		public int y;
		public int width;
		public int length;
		public int price;
		
		public boolean mark = false;
		
		public Plot (int id, int x, int y, int width, int length, int price) {
			this.id = id;
			this.x = x;
			this.y = y;
			this.width = width;
			this.length = length;
			this.price = price;
		}
		
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
		
		public TestCase(int width, int length, int money, int plotNum, Plot plots[]) {
			this.width = width;
			this.length = length;
			this.money = money;
			this.plotNum = plotNum;
			this.plots = plots;
		}
		
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
			System.out.println("--------------------");
			System.out.println(" - " + tests[i].toString());
			System.out.println(" result: " + solve(tests[i]));
		}
	}
	
	public static int solve(TestCase testCase) {
		
	}
	
	public static TestCase[] getTestCases(int caseNum, Scanner scanner) {
		System.out.println("--------------------");
		TestCase tests[] = new TestCase[caseNum];
		for (int i = 0; i < caseNum; i++) {
			System.out.println("Test case" + i + " : ");
			System.out.println("width: ");
			int w = scanner.nextInt();
			System.out.println("length: ");
			int l = scanner.nextInt();
			System.out.println("money: ");
			int money = scanner.nextInt();
			System.out.println("how many plots: ");
			int plotNum = scanner.nextInt();
			Plot plots[] = new Plot[plotNum];
			for (int j = 0; j < tests[i].plotNum; j++) {
				System.out.println("--------------------");
				System.out.println("x: ");
				int x = scanner.nextInt();
				System.out.println("y: ");
				int y = scanner.nextInt();
				System.out.println("width: ");
				int width = scanner.nextInt();
				System.out.println("length: ");
				int length = scanner.nextInt();
				System.out.println("price: ");
				int price = scanner.nextInt();
				plots[j] = new Plot(j, x, y, width, length, price);
			}
			tests[i] = new TestCase(w, l, money, plotNum, plots);
		}
		return tests;
	}
}