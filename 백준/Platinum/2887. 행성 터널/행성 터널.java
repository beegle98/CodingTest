import java.util.*;
import java.io.*;

public class Main {
    static class Node {
        int idx;
        int x;
        int y;
        int z;
        public Node(int idx, int x, int y, int z) {
            this.idx = idx;
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }
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
    static int N;
    static int[] parent;
    static ArrayList<Edge> edge = new ArrayList<>();
    static ArrayList<Node> node = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine());
            int a,b,c;
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            node.add(new Node(i,a,b,c));
        }
        makeEdge();
        Collections.sort(edge);
        makeSet();
        int cnt=0,sum=0;
        for(Edge e : edge) {
            if(cnt == N-1) break;
            if(union(e.to,e.from)) {
                sum+=e.cost;
                cnt++;
            }
        }
        System.out.println(sum);
    }
    private static void makeEdge() {
        node.sort(Comparator.comparingInt(o -> o.x));
        for(int i=1;i<N;i++) {
            Node a = node.get(i-1);
            Node b = node.get(i);
            edge.add(new Edge(a.idx,b.idx,b.x-a.x));
        }
        node.sort(Comparator.comparingInt(o -> o.y));
        for(int i=1;i<N;i++) {
            Node a = node.get(i-1);
            Node b = node.get(i);
            edge.add(new Edge(a.idx,b.idx,b.y-a.y));
        }
        node.sort(Comparator.comparingInt(o -> o.z));
        for(int i=1;i<N;i++) {
            Node a = node.get(i-1);
            Node b = node.get(i);
            edge.add(new Edge(a.idx,b.idx,b.z-a.z));
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

        if(a<b) parent[b] = a;
        else parent[a] = b;
        return true;
    }

}