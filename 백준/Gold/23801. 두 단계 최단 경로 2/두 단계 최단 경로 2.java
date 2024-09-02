import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {
    int idx;
    long cost;

    Node(int idx, long cost) {
        this.idx = idx;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node o) {
        return Long.compare(this.cost, o.cost);
    }
}

public class Main {
    static final long INF= (long)1e12;
    static ArrayList<Node>[] list;
    static int N,M;
    static PriorityQueue<Node> pq = new PriorityQueue<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        list = new ArrayList[N+1];
        
        for(int i=0;i<=N;i++) list[i] = new ArrayList<>();
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a,b,c;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			list[a].add(new Node(b,c));
			list[b].add(new Node(a,c));
		}
		st = new StringTokenizer(br.readLine());
		int start, end;
		start = Integer.parseInt(st.nextToken());
		end = Integer.parseInt(st.nextToken());
		int P = Integer.parseInt(br.readLine());
		int[] pList = new int[P];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<P;i++) {
			pList[i] = Integer.parseInt(st.nextToken());
		}
		long[] Cost1 = dijkstra(start);
		long[] Cost2 = dijkstra(end);
		long ans = Long.MAX_VALUE;
		for(int i=0;i<P;i++) {
			int idx = pList[i];
			ans = Math.min(ans, Cost1[idx] + Cost2[idx]);
		}
		if(ans>=INF) ans = -1;
		System.out.println(ans);
    }
    public static long[] dijkstra(int start) {
        pq.add(new Node(start,0));
        long[] Cost = new long[N+1];;
        Arrays.fill(Cost, INF);
        Cost[start] = 0;

        while (!pq.isEmpty()) {
            Node now = pq.poll();
            
            if (Cost[now.idx] < now.cost) continue;

            for (int i = 0; i < list[now.idx].size(); i++) {
                int nIdx = list[now.idx].get(i).idx;
                
                long nCost = now.cost + list[now.idx].get(i).cost;
                if (Cost[nIdx] > nCost) {
                    Cost[nIdx] = nCost;
                    pq.add(new Node(nIdx, nCost));
                }
            }
        }
        pq.clear();
        return Cost;
    }
}
