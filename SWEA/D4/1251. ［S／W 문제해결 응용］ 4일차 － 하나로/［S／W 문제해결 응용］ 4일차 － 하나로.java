import java.io.*;
import java.util.*;
/*
크루스칼
91,496 kb
메모리
561 ms
실행시간

프림

 */
public class Solution {
	static class Node implements Comparable<Node>{
		int idx;
		long cost;
		public Node(int idx, long cost) {
			super();
			this.idx = idx;
			this.cost = cost;
		}
		@Override
		public int compareTo(Node o) {
			return Long.compare(this.cost, o.cost);
		}
		
	}
	static final long INF = Long.MAX_VALUE;
	static int N;
	static long[][] list;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for(int tc=1;tc<=T;tc++) {
			sb.append("#" + tc + " ");
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			
			list = new long[N][2];
			for(int i=0;i<2;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					list[j][i] = Integer.parseInt(st.nextToken());
				}
			}

			double E = Double.parseDouble(br.readLine());
			
			long cost = prim();
			double ans;
			ans = E * cost;
			sb.append(String.format("%.0f",ans) + "\n");
		}
		System.out.println(sb.toString());
	}
	private static long len(int i, int j) {
		return (list[i][0]-list[j][0])*(list[i][0]-list[j][0]) + (list[i][1]-list[j][1])*(list[i][1]-list[j][1]);
	}
	private static long prim() {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		boolean[] visited = new boolean[N];
		long[] Dist = new long[N];
		Arrays.fill(Dist, INF);
		Dist[0]=0;
		pq.add(new Node(0,0));
		long sum = 0;
		
		while(!pq.isEmpty()) {
			Node cur = pq.poll();
			if(visited[cur.idx]) continue;
			
			sum += cur.cost;
			visited[cur.idx]=true;
			
			for(int i=0;i<N;i++) {
				if(visited[i]) continue;
				long dist = len(cur.idx,i);
				if(dist < Dist[i]) {
					Dist[i] = dist;
					pq.add(new Node(i,dist));
				}
			}
		}
		return sum;
	}
}