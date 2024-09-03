import java.io.*;
import java.util.*;

public class Main {
    
    static final int INF = (int)1e9;
    static final int[] dx = {1, 0, -1, 0};
    static final int[] dy = {0, 1, 0, -1};
    
    static int n;
    static int[][] MAP;
    static int[][] Cost;

    static class Node implements Comparable<Node> {
        int x, y, cost;

        Node(int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.cost, other.cost);
        }
    }

    static void dijkstra(Node start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(start);

        while (!pq.isEmpty()) {
            Node now = pq.poll();

            if (now.x == n - 1 && now.y == n - 1) break;
            if (Cost[now.x][now.y] < now.cost) continue;

            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                int nCost = now.cost + MAP[nx][ny];
                if (Cost[nx][ny] > nCost) {
                    Cost[nx][ny] = nCost;
                    pq.add(new Node(nx, ny, nCost));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int tc = 0;
        String line;

        while ((line = br.readLine()) != null) {
            n = Integer.parseInt(line);
            if (n == 0) break;
            
            MAP = new int[n][n];
            Cost = new int[n][n];
            for (int i = 0; i < n; i++) {
            	st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    MAP[i][j] = Integer.parseInt(st.nextToken());
                    Cost[i][j] = INF;
                }
            }
            dijkstra(new Node(0, 0, MAP[0][0]));
            sb.append("Problem ").append(++tc).append(": ").append(Cost[n - 1][n - 1]).append('\n');
        }

        System.out.print(sb.toString());
    }
}
