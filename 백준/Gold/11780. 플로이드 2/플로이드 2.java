import java.io.*;
import java.util.*;

public class Main {

    static final int INF = 1_000_000_007;
    static int n, m;
    static int[][] dist, via;
    static StringBuilder sb = new StringBuilder();
    static Deque<Integer> path = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        dist = new int[n + 1][n + 1];
        via = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            if (dist[r][c] > cost) {
                dist[r][c] = cost;
            }
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        via[i][j] = k;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] == INF) sb.append("0 ");
                else sb.append(dist[i][j]).append(" ");
            }
            sb.append("\n");
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || dist[i][j] == INF) {
                    sb.append("0\n");
                } else {
                    path.clear();
                    recursion(i, j);
                    sb.append(path.size()).append(" ");
                    for (int node : path) sb.append(node).append(" ");
                    sb.append("\n");
                }
            }
        }
        System.out.print(sb);
    }

    static void recursion(int start, int end) {
        if (via[start][end] == 0) {
            path.add(start);
            if (start != end) path.add(end);
        } else {
            int mid = via[start][end];
            recursion(start, mid);
            path.removeLast();
            recursion(mid, end);
        }
    }
}