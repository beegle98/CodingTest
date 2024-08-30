import java.io.*;
import java.lang.*;
import java.util.*;

/*
 * 306012kb	1220ms
 */

public class Main{//_2637_G2_장난감_조립_이현지 {
    static int n, m, x, y, k;
    static int[] arr;
    static boolean[] mid;
    static class Edge{
    	int from, to, weight;

		public Edge(int from, int to, int weight) {
			super();
			this.from = from;
			this.to = to;
			this.weight = weight;
		}
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        
        // count 계산해서 저장
        arr = new int[n+1];
        arr[n] = 1;
        mid = new boolean[n+1];
        
        // 진출 배열
        List<Edge>[] list = new ArrayList[n+1];
        for(int i=0; i<n+1; i++) {
        	list[i] = new ArrayList<>();
        }
        
        // 진입 차수 배열
        int[] inDegree = new int[n+1];
        
        // 진입차수 0 노드 큐
        LinkedList<Integer> q = new LinkedList<>();
        
        StringTokenizer st;
        for(int i=0; i<m; i++) {
        
        	st = new StringTokenizer(br.readLine());
        	x = Integer.parseInt(st.nextToken());
        	y = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            
            mid[x] = true;
            list[x].add(new Edge(x, y, k));
            inDegree[y]++;
        }
        // 다른 노드가 필요로 하지 않는 거 먼저!
        for(int i=1; i<n+1; i++) {
        	if(inDegree[i] == 0) q.offer(i);
        }
        
        // 큐에서 뺴면서 계산
        while(!q.isEmpty()) {
        	int cur = q.poll();
        	for(Edge edge : list[cur]) {
        		arr[edge.to] += arr[cur] * edge.weight;
//        		System.out.println(Arrays.toString(arr));
        		if(--inDegree[edge.to] == 0) {
        			q.offer(edge.to);
        		}
        	}
        }
        for(int i=1; i<n+1; i++) {
        	if(!mid[i]) {
        		System.out.println(i+" "+arr[i]);
        	}
        }
    }
}

