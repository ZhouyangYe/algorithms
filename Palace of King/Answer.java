/* package codechef; // don't place package name! */

import java.util.ArrayList;
import java.util.Scanner;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
    private final static int N = 1024;
    private static Node[] tree = new Node[2 * N];
    private static ArrayList<PlotHeight>[] plotAdd = new ArrayList[N];
    private static ArrayList<PlotHeight>[] plotSubtract = new ArrayList[N];

    private static void initialize() {
        for (int i = 0; i < N; i++) {
            plotAdd[i] = new ArrayList<>();
            plotSubtract[i] = new ArrayList<>();
        }
        buildTree();
    }


    public static void main(String[] args) {
        // your code goes here
        initialize();
        Scanner s = new Scanner(System.in);
        int testCases = s.nextInt();
        for (int t = 1; t <= testCases; t++) {
            int W = s.nextInt();
            int H = s.nextInt();
            long C = s.nextLong();
            int n = s.nextInt();

            Plot[] plots = new Plot[n];
            for (int i = 0; i < n; i++) {
                int w1 = s.nextInt();
                int h1 = s.nextInt();
                int w2 = s.nextInt();
                int h2 = s.nextInt();
                long cost = s.nextLong();

                w2 += w1;
                h2 += h1;
                plots[i] = new Plot(w1, h1, w2, h2, cost);
            }
            System.out.println("Case " + t + ": " + solve(W, H, C, plots));
        }
    }

    private static int solve(int W, int H, long C, Plot[] plots) {
        int ans = 0;
        for (int h = 1; h <= H; h++) {
            clear(W);

            for (Plot plot : plots) {
                int l = Math.max(0, plot.h1 - h + 1), r = Math.min(plot.h2, H - h + 1);
                plotAdd[plot.w1].add(new PlotHeight(l, r, plot.cost));
                plotSubtract[plot.w2].add(new PlotHeight(l, r, -plot.cost));
            }
            int r = 0;
            for (int l = 0; l < W; l++) {
                for (PlotHeight e : plotSubtract[l])
                    addInRange(1, e.x, e.y, e.cost);

                while (r <= W && getMin(1, 0, H - h + 1) <= C) {
                    for (PlotHeight e : plotAdd[r])
                        addInRange(1, e.x, e.y, e.cost);
                    r++;
                }
                ans = Math.max(ans, (r - l - 1) * h);
            }
        }
        return ans;
    }

    private static void buildTree() {
        for (int i = 0; i < N; i++)
            tree[N + i] = new Node(i, i + 1);
        for (int i = N - 1; i > 0; i--)
            tree[i] = new Node(tree[i << 1].l, tree[i << 1 | 1].r);
    }

    private static void push(int v) {
        tree[v << 1].cost += tree[v].toPush;
        tree[v << 1].toPush += tree[v].toPush;
        tree[v << 1 | 1].cost += tree[v].toPush;
        tree[v << 1 | 1].toPush += tree[v].toPush;

        tree[v].toPush = 0;
    }

    private static void clear(int w) {
        for (int i = 0; i <= w; i++) {
            plotAdd[i].clear();
            plotSubtract[i].clear();
        }
        int size = N << 1;
        for (int i = 1; i < size; i++) {
            tree[i].toPush = 0;
            tree[i].cost = 0;
        }
    }

    private static void update(int v) {
        tree[v].cost = Math.min(tree[v << 1].cost, tree[v << 1 | 1].cost);
    }

    private static void addInRange(int v, int l, int r, long c) {
        if (l <= tree[v].l && tree[v].r <= r) {
            tree[v].cost += c;
            tree[v].toPush += c;
            return;
        }
        if (l >= tree[v].r || tree[v].l >= r) return;
        push(v);
        addInRange(v << 1, l, r, c);
        addInRange(v << 1 | 1, l, r, c);
        update(v);
    }

    private static long getMin(int v, int l, int r) {
        if (l <= tree[v].l && tree[v].r <= r)
            return tree[v].cost;
        if (l >= tree[v].r || tree[v].l >= r)
            return Integer.MAX_VALUE;
        push(v);
        return Math.min(getMin(2 * v, l, r), getMin(2 * v + 1, l, r));
    }
}

class Node {
    int l, r;
    long cost = 0, toPush = 0;

    public Node(int l, int r) {
        this.l = l;
        this.r = r;
    }
}

class Plot {
    int w1, h1, w2, h2;
    long cost;

    public Plot(int w1, int h1, int w2, int h2, long cost) {
        this.w1 = w1;
        this.h1 = h1;
        this.w2 = w2;
        this.h2 = h2;
        this.cost = cost;
    }
}

class PlotHeight {
    int x, y;
    long cost;

    public PlotHeight(int x, int y, long cost) {
        this.x = x;
        this.y = y;
        this.cost = cost;
    }
}