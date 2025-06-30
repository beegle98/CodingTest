import java.util.*;
import java.io.*;

public class Main {
    static class Edge{
        int to;
        int from;
        int cost;
        public Edge(int to, int from, int cost) {
            super();
            this.to = to;
            this.from = from;
            this.cost = cost;
        }
    }
    static int N,M,K;
    static int[] parent;
    static ArrayList<Edge> edge;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        while(true){
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            if(N==0&&M==0&&K==0) break;

            edge =  new ArrayList<>();
            for(int i=0;i<M;i++) {
                st = new StringTokenizer(br.readLine());
                String c;
                int a,b;
                c = st.nextToken();
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                edge.add(new Edge(a,b,c.compareTo("B")==0?1:0));
            }
            int minBlueCnt = kruskal(0);
            int maxBlueCnt = kruskal(1);
            if(minBlueCnt <= K && K <= maxBlueCnt) {
                System.out.println("1");
            }else{
                System.out.println("0");
            }
        }
    }
    private static int kruskal(int mode){
        int cnt=0,sum=0;
        makeSet();
        if(mode==0){
            edge.sort(((o1, o2) -> o1.cost - o2.cost));
        }else{
            edge.sort(((o1, o2) -> o2.cost - o1.cost));
        }
        for(Edge e : edge) {
            if(cnt == N-1) break;
            if(union(e.to,e.from)) {
                sum+=e.cost;
                cnt++;
            }
        }
        return sum;
    }
    private static void makeSet() {
        parent = new int[N+1];
        for(int i=0;i<=N;i++) parent[i]=i;
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