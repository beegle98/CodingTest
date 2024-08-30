import java.io.*;
import java.util.*;

/*
 * 11812 KB
 * 64    ms
 */
public class Main {
	static class Edge {
		int node, weight;

		public Edge(int node, int weight) {
			this.node = node;
			this.weight = weight;
		}
	}
	static int N;
	static int[][] counts;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		
		List<Edge>[] edges = new ArrayList[N + 1];
		int[] inDegree = new int[N + 1];
		counts = new int[N + 1][N + 1];
		
		for (int i = 1; i <= N; i++) {
			edges[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int to = Integer.parseInt(st.nextToken());
			int from = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			
			edges[from].add(new Edge(to, weight));
			inDegree[to]++;
		}
		
		Queue<Integer> queue = new LinkedList<>();
		
		for (int i = 1; i <= N; i++) {
			if (inDegree[i] == 0) {
				counts[i][i] = 1;
				queue.add(i);
			}
		}
		
		while (!queue.isEmpty()) {
			int current = queue.poll();
			
			for (Edge edge : edges[current]) {
				int next = edge.node;
				int weight = edge.weight;
				
				sum(current, next, weight);
				if (--inDegree[next] == 0) {
					queue.add(next);
				}
			}
		}
		
		StringBuilder answer = new StringBuilder();
		for (int i = 1; i <= N; i++) {
			if (counts[N][i] == 0) continue;
			answer.append(i).append(" ").append(counts[N][i]).append("\n");
		}
		System.out.println(answer);
		
	}
	
	public static void sum(int from, int to, int weight) {
		for (int i = 1; i <= N; i++) {
			counts[to][i] += counts[from][i] * weight;
		}
	}
}
