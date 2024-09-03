import java.io.*;
import java.util.*;



public class Main {
	static class Node {
	    int idx;
	    long cost;

	    Node(int idx, long cost) {
	        this.idx = idx;
	        this.cost = cost;
	    }
	}
    static final long INF= (long)1e12;
    static ArrayList<Node>[] list;
    static int N,M;
    static PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> Long.compare(o1.cost, o2.cost));
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
		long[][] Dist = new long[P][N+1];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<P;i++) {
			pList[i] = Integer.parseInt(st.nextToken());
			Dist[i] = dijkstra(pList[i]);
		}
		long ans = Long.MAX_VALUE;
		for(int i=0;i<P;i++) {
			for(int j=0;j<P;j++) {
				if(j==i) continue;
				for(int k=0;k<P;k++) {
					if(k==j || k==i) continue;
					long sum = Dist[i][start] + Dist[i][pList[k]] + Dist[j][pList[k]] + Dist[j][end];
					ans = Math.min(ans, sum);
				}
			}
		}
		if(ans>=INF) ans = -1;
		System.out.println(ans);
    }
    
	public static long[] dijkstra(int start) {
        pq.add(new Node(start,0));
        long[] Cost = new long[N+1];
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
