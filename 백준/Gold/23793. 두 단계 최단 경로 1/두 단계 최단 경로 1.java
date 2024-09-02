import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {
    int idx, cost;

    Node(int idx, int cost) {
        this.idx = idx;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node o) {
        return Integer.compare(this.cost, o.cost);
    }
}

public class Main {
    static final int INF = (int)1e9;
    static ArrayList<Node>[] list;
    static int[] Cost ;
    static int N,M;
    static PriorityQueue<Node> pq = new PriorityQueue<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        list = new ArrayList[N+1];
        Cost = new int[N+1];
        for(int i=0;i<=N;i++) list[i] = new ArrayList<>();
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a,b,c;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			list[a].add(new Node(b,c));
		}
		st = new StringTokenizer(br.readLine());
		int start, mid, end;
		start = Integer.parseInt(st.nextToken());
		mid = Integer.parseInt(st.nextToken());
		end = Integer.parseInt(st.nextToken());
		int a1,a2,a3;
		dijkstra(start,mid,0);
		a1 = Cost[mid];
		dijkstra(mid,end,0);
		a2 = Cost[end];
		dijkstra(start,end,mid);
		a3 = Cost[end];
		int ans1 = a1+a2, ans2 = a3;
		if(a1 == INF || a2==INF) ans1 = -1;
		if(a3 == INF) ans2 = -1;
		System.out.println(ans1 + " " + ans2);
    }
    public static void dijkstra(int start,int end,int stop) {
        pq.add(new Node(start,0));
        Arrays.fill(Cost, INF);
        Cost[start] = 0;

        while (!pq.isEmpty()) {
            Node now = pq.poll();
            
            if (now.idx==end) break;
            if (Cost[now.idx] < now.cost) continue;

            for (int i = 0; i < list[now.idx].size(); i++) {
                int nIdx = list[now.idx].get(i).idx;
                if(nIdx==stop) continue;
                int nCost = now.cost + list[now.idx].get(i).cost;
                if (Cost[nIdx] > nCost) {
                    Cost[nIdx] = nCost;
                    pq.add(new Node(nIdx, nCost));
                }
            }
        }
        pq.clear();
    }
}
