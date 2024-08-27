import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class Main{//_2252_G3_줄_세우기_이현지 {
	
	static int N , M;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			
			ArrayList<Integer>[] list = new ArrayList[N+1];
			
			int[] inDegree = new int[N+1];
			
			ArrayList<Integer> result = new ArrayList<>();
			
			LinkedList<Integer> q = new LinkedList<>();
			
			for(int i=1; i<N+1; i++) {
				list[i] = new ArrayList<>();
			}
			
			
			for(int i=0; i<M; i++) {
				st = new StringTokenizer(br.readLine());
				int from = Integer.parseInt(st.nextToken());
				int to = Integer.parseInt(st.nextToken());
				list[from].add(to);
				inDegree[to]++;
			}
			
			for(int i=1; i<N+1; i++) {
				if(inDegree[i] == 0) {
					q.add(i);
				}
			}
			
			while(!q.isEmpty()) {
				int cur = q.poll();
				result.add(cur);
				
				for(int i=0, end = list[cur].size(); i<end; i++) {
					int ad = list[cur].get(i);
					
					if(--inDegree[ad] == 0) {
						q.add(ad);
					}
				}
			}
			int size = result.size();
			if(size == N) {
				for(int i=0; i<size; i++) {
					System.out.print(result.get(i)+" ");
				}
				
			}
			System.out.println();
	}
}
