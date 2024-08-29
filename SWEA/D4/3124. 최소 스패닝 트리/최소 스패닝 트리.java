import java.io.*;
import java.util.*;

public class Solution {

	private static class Edge implements Comparable<Edge>{
		int strat, end, weight;

		public Edge(int strat, int end, int weight) {
			super();
			this.strat = strat;
			this.end = end;
			this.weight = weight;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(this.weight, o.weight);
		}
	}
	static int V,E;
	static int[] parents;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for(int tc=1;tc<=T;tc++) {
			sb.append("#" + tc + " ");
			StringTokenizer st = new StringTokenizer(br.readLine());
			V = Integer.parseInt(st.nextToken());
			E = Integer.parseInt(st.nextToken());
			parents = new int[V+1];
			Edge[] edges = new Edge[E];
			
			for(int i=0;i<E;i++) {
				st = new StringTokenizer(br.readLine());
				int from = Integer.parseInt(st.nextToken());
				int to = Integer.parseInt(st.nextToken());
				int weight = Integer.parseInt(st.nextToken());
				edges[i] = new Edge(from, to, weight);
			}
			
			Arrays.sort(edges); //간선의 가중치 기준 오름차순 정렬
			make(); // 모든 정점을 분리집합으로 만듬 (단위 서로소 집합<트리> 생성)
			int cnt=0;
			long cost=0;
			for(Edge edge : edges) {
				if(union(edge.strat, edge.end)) {
					cost += edge.weight;
					if(++cnt == V-1) break; // MST 완성!!
				}
			}
			sb.append(cost + "\n");
		}
		System.out.println(sb.toString());
	}
	private static void make() {
		for(int i=1;i<=V;i++) {
			parents[i]=-1;
		}
	}
	private static int findSet(int a) {
		if(parents[a]<0) return a;
		return parents[a] = findSet(parents[a]); // 경로 압축!!
	}
	static boolean union(int a,int b) {
		a = findSet(a);
		b = findSet(b);
		if(a==b) return false;
		
		// 편의상 a집합에 b집합을 붙임 (집합의 크기에 따라 붙이도록 처리 가능!!)
		parents[a] += parents[b]; // 집합 크기관리 (절댓값 = 집합의 크기)
		parents[b] = a;
		return true;
	}
}
