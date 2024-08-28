import java.util.*;
import java.io.*;

public class Solution {
	static class Node implements Comparable<Node>{
		int cnt;
		int value;
		public Node(int cnt, int value) {
			super();
			this.cnt = cnt;
			this.value = value;
		}
		@Override
		public int compareTo(Node o) {
			if(this.cnt!=o.cnt) return this.cnt - o.cnt;
			return this.value - o.value;
		}
	}
	static final int N = 100;
	static int ans;
	static ArrayList<Integer>[] list = new ArrayList[N+1];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = 10;
		for(int tc=1;tc<=T;tc++) {
			for(int i=1;i<=N;i++) list[i] = new ArrayList<>();
			StringTokenizer st = new StringTokenizer(br.readLine());
			int M = Integer.parseInt(st.nextToken()); 
			int start = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<M/2;i++){
				int a,b;
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				list[a].add(b);
			}
			ans = start;
			bfs(start);
			System.out.println("#" + tc+ " " + ans);
		}
	}
	private static void bfs(int start) {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		boolean[] visited = new boolean[N+1];
		pq.add(new Node(0,start));
		visited[start]=true;
		while(!pq.isEmpty()) {
			Node cur = pq.poll();
			ans = cur.value;
			for(int i=0;i<list[cur.value].size();i++) {
				int x= list[cur.value].get(i);
				if(!visited[x]) {
					pq.add(new Node(cur.cnt+1,x));
					visited[x]=true;
				}
			}
		}
	}
}
