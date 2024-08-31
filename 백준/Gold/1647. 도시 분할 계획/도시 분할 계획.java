import java.util.*;
import java.io.*;

public class Main {
	static class Node implements Comparable<Node>{
		int to;
		int from;
		int cost;
		public Node(int to, int from, int cost) {
			super();
			this.to = to;
			this.from = from;
			this.cost = cost;
		}
		@Override
		public int compareTo(Main.Node o) {
			return this.cost - o.cost;
		}
		
	}
	static int N,M;
	static int[] parent;
	static PriorityQueue<Node> edges = new PriorityQueue<Node>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int a,b,c;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			edges.add(new Node(a,b,c));
		}
		makeSet();
		int cnt=0,sum=0;
		while(!edges.isEmpty() && cnt < N-2) {
			Node cur = edges.poll();
			if(union(cur.to,cur.from)) {
				sum+=cur.cost;
				cnt++;
			}
		}
		System.out.println(sum);
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
		parent[b] = a;
		return true;
	}
	
}
