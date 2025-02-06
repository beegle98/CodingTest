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
    static ArrayList<Edge> edges = new ArrayList<Edge>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        while(true) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            if(N==0 && M==0) {
                break;
            }
            long s = 0;
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int a, b, c;
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                c = Integer.parseInt(st.nextToken());
                s += c;
                edges.add(new Edge(a, b, c));
            }
            Collections.sort(edges);
            makeSet();
            long cnt = 0, sum = 0;
            for (Edge e : edges) {
                if (cnt == N - 1)
                    break;
                if (union(e.to, e.from)) {
                    sum += e.cost;
                    cnt++;
                }
            }
            edges.clear();
            System.out.println(s - sum);
        }
    }
    private static void makeSet() {
        parent = new int[N];
        for(int i=0;i<N;i++) parent[i]=i;
    }
    private static int find(int a) {
        if(parent[a]==a) return a;
        return parent[a] = find(parent[a]);
    }
    private static boolean union(int a, int b) {
        a = find(a);
        b = find(b);
        if(a==b) return false;

        // if문을 쓰는 이유: 트리를 한 쪽으로 몰아서 항상 큰 트리에 작은 트리가 합쳐질 수 있게 하여 트리 균형 유지(최적화)
        // 물론 완벽하게 균형을 유지할 수 있는것도 아니라 시간에 별 차이는 없다. 즉, 없어도 무관
        if(a<b) parent[b] = a;
        else parent[a] = b;
        return true;
    }

}
