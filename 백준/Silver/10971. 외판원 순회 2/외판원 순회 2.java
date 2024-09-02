import java.io.*;
import java.util.*;

//

public class Main{//_10971_S2_외판원_순회_2_이현지 {
    static int N, ans, cnt, min;
    static boolean[] visited;
    static ArrayList<Edge> edges;
    static Edge cur;
    
    static public class Edge implements Comparable<Edge>{
    	int from, to, weight;
		public Edge(int from, int to, int weight) {
			super();
			this.from = from;
			this.to = to;
			this.weight = weight;
		}
		@Override
		public int compareTo(Edge o) {
			return this.weight-o.weight;
		}
		@Override
		public String toString() {
			return "Edge [from=" + from + ", to=" + to + ", weight=" + weight + "]";
		}
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        
        edges = new ArrayList<Edge>();
        StringTokenizer st;
        for(int i=0; i<N; i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j=0; j<N; j++) {
        		int x = Integer.parseInt(st.nextToken());
        		if(x!=0)
        			edges.add(new Edge(i,j,x));
        	}
        }
        //Collections.sort(edges);
        min = Integer.MAX_VALUE;

        for(Edge e : edges) {
            if(e.from == 0) {
                cnt = 1;
                visited = new boolean[N];
                ans = e.weight;
                cur = e;
                //        			System.out.println(cur.toString());
                visited[cur.to]= true;
                search(cur,cnt,visited,ans);
            }
        }
        
        System.out.println(min);
    }
    public static void search(Edge edge, int cnt, boolean[] visited, int ans) {
//    	for(int i=0; i<N; i++) {
//    		System.out.print(visited[i]+" ");
//    	}
//    	System.out.println(ans);
    	
    	if(cnt == N-1) {
    		for(Edge e : edges) {
        		if(edge.to == e.from && e.to == cur.from) {
//        			System.out.println(e.toString());
        			min = Math.min(min, ans+e.weight);
//        			System.out.println("min: "+min);
//                    return;
        		}
    		}
    		return;
    	}
    	for(Edge e : edges) {
    		if(e.from == edge.to && e.to!=edge.from && e.to!=cur.from && !visited[e.to]) {
//    			System.out.println(e.toString());
    			visited[e.to] = true;
    			search(e, cnt+1, visited, ans+e.weight);
    			visited[e.to] = false;
    		}
    	}
        return;
    }
}

