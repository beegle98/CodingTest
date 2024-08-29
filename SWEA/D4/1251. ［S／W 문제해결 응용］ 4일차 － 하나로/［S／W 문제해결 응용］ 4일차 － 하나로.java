import java.io.*;
import java.util.*;

public class Solution {

	private static class Edge implements Comparable<Edge>{
		int start, end;
		long weight;

		public Edge(int start, int end, long weight) {
			super();
			this.start = start;
			this.end = end;
			this.weight = weight;
		}

		@Override
		public int compareTo(Edge o) {
			return Long.compare(this.weight, o.weight);
		}
	}
	static int V;
	static int[] parents;
	static long[][] list;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for(int tc=1;tc<=T;tc++) {
			sb.append("#" + tc + " ");
			StringTokenizer st = new StringTokenizer(br.readLine());
			V = Integer.parseInt(st.nextToken());
			parents = new int[V];
			ArrayList<Edge> edges = new ArrayList<>();
			list = new long[V][2];
			for(int i=0;i<2;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<V;j++) {
					list[j][i] = Integer.parseInt(st.nextToken());
				}
			}

			double E = Double.parseDouble(br.readLine());
			for(int i=0;i<V;i++) {
				for(int j=i+1;j<V;j++) {
					long weight = len(i,j);
					edges.add(new Edge(i, j, weight));
				}
			}
			Collections.sort(edges); //간선의 가중치 기준 오름차순 정렬
			make(); // 모든 정점을 분리집합으로 만듬 (단위 서로소 집합<트리> 생성)
			int cnt=0;
			long cost=0;
			for(Edge edge : edges) {
				if(union(edge.start, edge.end)) {
					cost += edge.weight;
					if(++cnt == V-1) break; // MST 완성!!
				}
			}
			double ans;
			ans = E * cost;
			sb.append(String.format("%.0f",ans) + "\n");
		}
		System.out.println(sb.toString());
	}
	private static long len(int i, int j) {
		return (list[i][0]-list[j][0])*(list[i][0]-list[j][0]) + (list[i][1]-list[j][1])*(list[i][1]-list[j][1]);
	}
	private static void make() {
		for(int i=0;i<V;i++) {
			parents[i]=i;
		}
	}
	private static int findSet(int a) {
		if(parents[a]==a) return a;
		return parents[a] = findSet(parents[a]); // 경로 압축!!
	}
	static boolean union(int a,int b) {
		a = findSet(a);
		b = findSet(b);
		if(a==b) return false;
		if(a>b) parents[a] = b;
		else parents[b] = a;
		return true;
	}
}