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
			
			//cost = kruskal();
			cost = prim_v2();
			//cost = prim_pq();
			
			double ans;
			ans = E * cost;
			sb.append(String.format("%.0f",ans) + "\n");
		}
		System.out.println(sb.toString());
	}
	private static long prim_v2() {
		
		//간선의 정보를 저장할 인접행렬
		long[][] map = new long[V][V];
		for(int i = 0; i < V; i++) {
			for (int j = i+1; j < V; j++) {
				map[i][j] = map[j][i] = len(i,j);  
			}
		}
		//방문 여부 배열(트리에 포함된 정점 배열)
		boolean[] visited = new boolean[V];
		//선택한 정정과 타정점들간의 간선 비용 중 최소 간선 비용을 저장
		long[] minEdge = new long[V];
		Arrays.fill(minEdge, Long.MAX_VALUE);
		
		int[] p = new int[V];
		
		//임의의 노드  	>>>>>처음으로 탐색하는  노드는 0
		minEdge[0] = 0;          // 선택된 노드에서 나가는 간선의 최소값을 저장하는 배열 
		p[0] = -1;				 // index에 해당하는 정점이 선택한 정점 정보
		
		//최소값, 최소값의 위치, 간선비용의합 을 저장할 변수
		long min,cost=0;
		int minVertex;
		
		//시작정점을 뺀 나머지 정점 수 만큼 반복
		int c =0;
		for(c= 0; c < V; c++) {
			min = Long.MAX_VALUE;
			minVertex = -1;  //index 정점에서 출발하는 모든 간선에 대해 dist를 업데이트 
			//step1. 트리 구성에 포함될 가장 유리한 정점 선택
			//       => 미 방문(비트리) 정점 중 최소 간선 비용의 정점을 선택 
			for(int i = 0; i < V; i++) {
				if( !visited[i] && minEdge[i] < min ) {
					min = minEdge[i];		//최소 비용 update
					minVertex = i;			//최소 비용의 정점 선택
				}
			}
			
			if(minVertex == -1) break;
			cost += min;				//신장 트리 비용 누적
			visited[minVertex] = true;  //트리 정점에 포함하기 위해 방문 체크
			
//			step2. 선택된 정점과 타 정점들의 간선 비용 비교하기  
//			선택된 정점을 기준으로 비트리 정점들과의 간선 비용을 고려해서 최적 업데이트
			for(int i = 0; i < V; i++) {
				//방문 안한 정점  중             연결이 되어 있고      minEdge에 저장된 값보다  가중치가 낮다면
				if( !visited[i] && map[minVertex][i]!=0 && map[minVertex][i]< minEdge[i] ) {
					p[i] = minVertex;
					minEdge[i] = map[minVertex][i];
				}
			}
		}
		return cost;
	}
	private static long kruskal() {
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
	private static long prim_pq() {
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