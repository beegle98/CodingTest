import java.io.*;
import java.util.*;

public class Main {
    static class Edge {
        int start, end, weight;
        public Edge(int s, int e, int w) {
            start = s;
            end = e;
            weight = w;
        }
        public boolean isPQ(int p, int q) {
            return (start == p && end == q) || (start == q && end == p);
        }
    }
    static int[] parent;
    static List<Edge> edges;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            edges = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                edges.add(new Edge(a, b, w));
            }
            System.out.println(solve(n, p, q) ? "YES" : "NO");
        }
    }

    static int findSet(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findSet(parent[x]);
    }

    static boolean unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return false;
        parent[a] = b;
        return true;
    }

    static boolean solve(int n, int p, int q) {
        edges.sort(Comparator.comparingInt(e -> e.weight));
        parent = new int[n + 1];
        for (int i = 1; i <= n; i++) parent[i] = i;

        boolean pqInMST = false;
        int cnt = 0;
        for (Edge edge : edges) {
            if (unionSet(edge.start, edge.end)) {
                cnt++;
                if (edge.isPQ(p, q)) pqInMST = true;
                if (cnt == n - 1) break;
            }
        }
        return pqInMST;
    }
}
