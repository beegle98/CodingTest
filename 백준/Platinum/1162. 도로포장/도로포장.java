import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static final long INF = (long)1e12;
	static int V, E, K, start;
	static ArrayList<Node>[] graph;
	static long[][] dist;
	static class Node {
		int idx;
		long cost;
		int k;

		Node(int idx, long cost, int k) {
			this.idx = idx;
			this.cost = cost;
			this.k = k;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		graph = new ArrayList[V+1];
		for (int i = 0; i < V + 1; i++) {
			graph[i] = new ArrayList<>();
		}
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			graph[a].add(new Node(b, c, 0));
			graph[b].add(new Node(a, c, 0));
		}
		start = 1;
		dist = new long[V + 1][K + 1];
		for (int i = 0; i <= V; i++) {
			for(int j = 0; j <= K; j++) dist[i][j] = INF;
		}
		dijkstra();
		long ans = INF;
		for(int i=0;i<=K;i++) ans = Long.min(ans,dist[V][i]);
		System.out.println(ans);
	}

	private static void dijkstra() {
		PriorityQueue<Node> q = new PriorityQueue<Node>((o1, o2) -> Long.compare(o1.cost, o2.cost));
		q.offer(new Node(start, 0, 0));
		dist[start][0] = 0;
		
		while (!q.isEmpty()) {
			Node cur = q.poll();
			
			if (dist[cur.idx][cur.k] < cur.cost) continue;

			for (int i = 0; i < graph[cur.idx].size(); i++) {
				Node next = graph[cur.idx].get(i);

				if (dist[next.idx][cur.k] > cur.cost + next.cost) {
					dist[next.idx][cur.k] = cur.cost + next.cost;
					q.offer(new Node(next.idx, dist[next.idx][cur.k], cur.k));
				}
				if (cur.k < K && dist[next.idx][cur.k+1] > cur.cost) {
					dist[next.idx][cur.k+1] = cur.cost;
					q.offer(new Node(next.idx, dist[next.idx][cur.k+1], cur.k+1));
				}
			}
		}
	}
}