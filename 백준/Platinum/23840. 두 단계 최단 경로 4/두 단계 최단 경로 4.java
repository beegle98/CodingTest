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
    static final int MAX = 1 << 21;
    static int fullBit;
    static long[][] dp = new long[21][MAX];
    static long[][] w = new long[21][21];
    static final long INF= (long)1e12;
    static ArrayList<Node>[] list;
    static long[][] Dist;
    static int[] pList;
    static int N,M,start,end;
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

		start = Integer.parseInt(st.nextToken());
		end = Integer.parseInt(st.nextToken());
		int P = Integer.parseInt(br.readLine());
		P++;
		pList = new int[P];
		Dist = new long[P][N+1];
		
		st = new StringTokenizer(br.readLine());
		pList[0] = start;
		Dist[0] = dijkstra(start);
		//시작점(start)도 넣어준다.
		for(int i=1;i<P;i++) {
			pList[i] = Integer.parseInt(st.nextToken());
			Dist[i] = dijkstra(pList[i]);
		}
		
		// pList 외판원 순회 시작
		fullBit = (1 << P) - 1;
        for (long[] i : dp) {
            Arrays.fill(i, -1);
        }
        
		// w[][] 만들어주기
		for(int i=0;i<P;i++) {
			for(int j=i+1;j<P;j++) {
				w[i][j]=w[j][i]=Dist[i][pList[j]];
			}
		}
        
    // 다익스트라 때리고 거리 알아낸 다음 외판원 순회를 돌리면 된다. 
    long ans = dfs(0,1);
		if(ans >= INF) ans = -1;
		System.out.println(ans);
    }
    private static long dfs(int cur, int visited) {
        if (visited == fullBit) {
           return Dist[cur][end];
        }

        if (dp[cur][visited] != -1) return dp[cur][visited];

        dp[cur][visited] = INF;
        for (int i = 0; i < pList.length; i++) {
            if (w[cur][i] == 0 || (visited & (1 << i)) != 0) continue;
            dp[cur][visited] = Math.min(dp[cur][visited], w[cur][i] + dfs(i, visited | (1 << i)));
        }

        return dp[cur][visited];
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
