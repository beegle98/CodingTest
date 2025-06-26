import java.util.*;
import java.io.*;

public class Main {
    static class Edge implements Comparable<Edge>{
        int to;
        int from;
        int cost;
        public Edge(int to, int from, int cost) {
            super();
            this.to = to;
            this.from = from;
            this.cost = cost;
        }
        @Override
        public int compareTo(Main.Edge o) {
            return this.cost - o.cost;
        }
    }
    static int N,M;
    static int[] parent;
    static int[] nodeCost;
    static ArrayList<Edge> edges = new ArrayList<Edge>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        nodeCost = new int[N+1];
        int MinNodeCost = Integer.MAX_VALUE;
        for(int i = 1; i <= N; i++){
            st = new StringTokenizer(br.readLine());
            nodeCost[i] = Integer.parseInt(st.nextToken());
            MinNodeCost = Math.min(MinNodeCost, nodeCost[i]);
        }
        for(int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine());
            int a,b,c;
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            if(a!=b) edges.add(new Edge(a,b,2*c+nodeCost[a]+nodeCost[b]));
        }
        Collections.sort(edges);
        makeSet();
        int cnt=0,sum=0;
        for(Edge e : edges) {
            if(cnt == N-1) break;
            if(union(e.to,e.from)) {
                sum+=e.cost;
                cnt++;
            }
        }
        System.out.println(sum+MinNodeCost);
    }
    private static void makeSet() {
        parent = new int[N+1];
        for(int i=1;i<=N;i++) parent[i]=i;
    }
    private static int find(int a) {
        if(parent[a]==a) return a;
        return parent[a] = find(parent[a]);
    }
    private static boolean union(int a, int b) {
        a = find(a);
        b = find(b);
        if(a==b) return false;

        if(a<b) parent[b] = a;
        else parent[a] = b;
        return true;
    }

}