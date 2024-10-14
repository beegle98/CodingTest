import java.util.*;
import java.io.*;

public class Main {
    static final int MAX = (int)1e9+7;
    static final int MIN = 0;
    static int[] s = new int[100010];
    static Tree[] tree = new Tree[400010];

    static class Tree {
        int max;
        int min;

        Tree(int max, int min) {
            this.max = max;
            this.min = min;
        }
    }

    static Tree cmp(Tree a, Tree b) {
        return new Tree(Math.max(a.max, b.max), Math.min(a.min, b.min));
    }

    static Tree init(int node, int start, int end) {
        int mid = (start + end) / 2;
        if (start == end) {
            return tree[node] = new Tree(s[start], s[start]);
        } else {
            return tree[node] = cmp(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
        }
    }

    static Tree compare(int node, int start, int end, int LL, int RR) {
        int mid = (start + end) / 2;
        if (LL > end || RR < start) {
            return new Tree(MIN, MAX);
        }
        if (LL <= start && RR >= end) return tree[node];
        return cmp(compare(node * 2, start, mid, LL, RR), compare(node * 2 + 1, mid + 1, end, LL, RR));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        
        for (int i = 1; i <= n; i++) s[i] = Integer.parseInt(br.readLine());

        init(1, 1, n);

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int t1 = Integer.parseInt(st.nextToken());
            int t2 = Integer.parseInt(st.nextToken());
            Tree t = compare(1, 1, n, t1, t2);
            System.out.println(t.min);
        }

        br.close();
    }
}