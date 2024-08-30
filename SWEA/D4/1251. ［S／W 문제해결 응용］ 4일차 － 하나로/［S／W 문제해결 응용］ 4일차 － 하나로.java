import java.io.*;
import java.util.*;


/*
크루스칼
91,496 kb
메모리
561 ms
실행시간

프림
ElogV
30,784 kb
메모리
208 ms
실행시간

V^2

 */
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
			list = new long[V][2];
			for(int i=0;i<2;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<V;j++) {
					list[j][i] = Integer.parseInt(st.nextToken());
				}
			}

			double E = Double.parseDouble(br.readLine());
			
			long cost;
			
			//cost = kruskal_pq();
			cost = kruskal_v2();
			//cost = prim();
			
			double ans;
			ans = E * cost;
			sb.append(String.format("%.0f",ans) + "\n");
		}
		System.out.println(sb.toString());
	}
	private static long kruskal_v2() {
		
		ArrayList<Integer> selected = new ArrayList<Integer>(V);
		boolean[] visited = new boolean[V];
		
		selected.add(0);		//0번 정점부터 시작
		visited[0] = true;
		
		//map 만들기
		long[][] map = new long[V][V];
		for(int i = 0; i < V; i++) {
			for (int j = i+1; j < V; j++) {
				map[i][j] = map[j][i] = len(i,j);  
			}
		}
		//시작정점을 뺀 나머지 정점을 선택하기 위해 남은 정점 만큼 반복
		long res=0;
		int index;
		long min;
		for (int i = 0; i < V-1; i++) {
			min = Long.MAX_VALUE;	//가장 작은 가중치 값
			index = 0;					//가중치가 가장 작은 정점의 index
			for (Integer v : selected) {
				//선택된 정점에서 갈수 있는 모든 정점의 가중치를 비교해서 최소가 되는 정점을 찾기 
				for (int j = 0; j < V; j++) { //인접된 정점 탐색
					// 정점이 인접되어 있고    인접된 정점이 방문하지 않은 정점이면서  가중치가 작다면  
					if(map[v][j]!=0 && !visited[j] && map[v][j] <min) { 
						min = map[v][j];		//새로운 최소값이므로  임시 선택
						index = j;				//최소값에 해당하는 정점을 기억
					}
				}
			}
			res += min;						//최소의 합을 구하기
			selected.add(index);				//선택한 최저 가중치에 해당하는 정점을 추가 
			visited[index] = true;				//선택했기 때문에 방문 표시 
		}
		return res;
	}
	private static long kruskal_pq() {
		parents = new int[V];
		ArrayList<Edge> edges = new ArrayList<>();

		for(int i=0;i<V;i++) {
			for(int j=i+1;j<V;j++) {
				long weight = len(i,j);
				edges.add(new Edge(i, j, weight));
			}
		}
		Collections.sort(edges); //간선의 가중치 기준 오름차순 정렬
		make(); // 모든 정점을 분리집합으로 만듬 (단위 서로소 집합<트리> 생성)
		
		int cnt=0;
		long res=0;
		for(Edge edge : edges) {
			if(union(edge.start, edge.end)) {
				res += edge.weight;
				if(++cnt == V-1) break; // MST 완성!!
			}
		}
		return res;
	}
	private static long prim() {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		boolean[] visited = new boolean[V];
		long[] Dist = new long[V];
		Arrays.fill(Dist, INF);
		Dist[0]=0;
		pq.add(new Node(0,0));
		long sum = 0;
		
		while(!pq.isEmpty()) {
			Node cur = pq.poll();
			if(visited[cur.idx]) continue;
			
			sum += cur.cost;
			visited[cur.idx]=true;
			
			for(int i=0;i<V;i++) {
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