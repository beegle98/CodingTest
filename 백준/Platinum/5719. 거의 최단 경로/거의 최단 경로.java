import java.io.*;
import java.util.*;

public class Main {
    static class Node implements Comparable<Node> {
        int idx;
        int cost;
        Node(int idx, int cost) {
            this.idx = idx;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }
    static List<Node>[] map;
    static int[] dp;
    static List<Integer>[] removeEdge;
    static boolean[][] delEdge;
    static int n, m;
    static int start, end;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        while(true){
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            if(n==0 && m==0) break;

            st = new StringTokenizer(br.readLine());
            start = Integer.parseInt(st.nextToken());
            end = Integer.parseInt(st.nextToken());

            dp = new int[n];
            map = new ArrayList[n];
            removeEdge = new ArrayList[n];
            delEdge = new boolean[n][n];

            for (int i = 0; i < n; i++) {
                map[i] = new ArrayList<>();
                removeEdge[i] = new ArrayList<>();
                dp[i] = Integer.MAX_VALUE;
            }

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int cost = Integer.parseInt(st.nextToken());
                map[u].add(new Node(v, cost));
            }

            dijk();
            removeDFS(end); // 모든 최단 경로 간선 삭제
            Arrays.fill(dp, Integer.MAX_VALUE);
            dijk();
            sb.append(dp[end]==Integer.MAX_VALUE ? -1 : dp[end]);
            sb.append('\n');
        }
        System.out.println(sb);
    }

    static void dijk() {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        dp[start] = 0;
        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            if(cur.idx==end || cur.cost > dp[cur.idx]) continue;
            for(Node n : map[cur.idx]) {
                if(delEdge[cur.idx][n.idx]) continue;
                int nCost = cur.cost + n.cost;
                if(nCost==dp[n.idx]){
                    removeEdge[n.idx].add(cur.idx);
                }else if(nCost<dp[n.idx]){
                    removeEdge[n.idx] = new ArrayList<>();
                    removeEdge[n.idx].add(cur.idx);
                    dp[n.idx] = nCost;
                    pq.offer(new Node(n.idx, nCost));
                }
            }
        }
    }

    static void removeDFS(int idx) {
        if(idx==start) return;
        for(int i : removeEdge[idx]){
            if(delEdge[i][idx]) continue;
            delEdge[i][idx] = true;
            removeDFS(i);
        }
    }
}