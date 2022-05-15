import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;
import java.lang.Math;

class Main {
	private static class Node {
		private int id;
		public String value;
		public Node left;
		public Node right;
		public Node parent;
		public int level = 0;
		
		public Node(int id, String value, Node left, Node right) {
			this.id = id;
			this.value = value;
			this.left = left;
			this.right = right;
			this.parent = null;
		}
		
		public Node(int id, String value, Node parent, Node left, Node right) {
			this.id = id;
			this.value = value;
			this.left = left;
			this.right = right;
			this.parent = parent;
			this.level = parent.level + 1;
		}
		
		public int getId() {
			return this.id;
		}
		
		public String toString() {
			String parentStr = this.parent == null ? "" : ", parent: " + this.parent.id;
			String leftStr = this.left == null ? "" : ", left: " + this.left.toString();
			String rightStr = this.right == null ? "" : ", right: " +this.right.toString();
			return "{id: " + this.id + ", level: " + this.level + ", value: \"" + this.value + "\"" + parentStr + leftStr + rightStr + "}";
		}
	}
	
	private static class Tree {
		private Node root;
		private int count = 0;
		private HashMap<Integer, Node> cache = new HashMap<Integer, Node>();
		private ArrayList<Node> slots = new ArrayList<Node>();
		
		public Tree(String value) {
			this.root = new Node(count++, value, null, null);
			cache.put(this.root.getId(), this.root);
			slots.add(this.root);
		}
		
		public boolean addNode(int id, String value, boolean toLeft) {
			Node parent = cache.get(id);
			if (parent != null) {
				if ((toLeft && parent.left != null) || (!toLeft && parent.right != null)) {
					return false;
				}
				Node node = new Node(count++, value, parent, null, null);
				cache.put(node.getId(), node);
				slots.add(node);
				if (toLeft) {
					parent.left = node;
				} else {
					parent.right = node;
				}
				if (parent.left != null && parent.right != null) {
					slots.remove(parent);
				}
				return true;
			}
			return false;
		}
		
		public void generateRandomTree(int num) {
			for (int i = 0; i < num; i++) {
				int size = slots.size();
				int randomIndex = (int) (size * Math.random());
				int randomNodeId = slots.get(randomIndex).getId();
				
				boolean toLeft = (int) (2 * Math.random()) == 0;
				boolean succeed = this.addNode(randomNodeId, "node-" + count, toLeft);
				if (!succeed) {
					this.addNode(randomNodeId, "node-" + count, !toLeft);
				}
			}
		}
		
		public void printTree() {
			System.out.println(this.root.toString());
		}
	}
	
	public static void main(String args[]) {
		Tree tree = new Tree("root");
		tree.generateRandomTree(18);
		tree.printTree();
	}
}