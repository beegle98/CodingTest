import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		//입력 받기
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()); // 정점 개수
		int E = Integer.parseInt(st.nextToken()); // 간선 개수
		
		//진출을 담을 배열 선언
		ArrayList<Integer>[] list = new ArrayList[N+1];
		
		//진입 차수를 위한 배열 선언
		int[] inDegree = new int[N+1];
		
		//위상 정렬한 결과를 담을 리스트
		ArrayList<Integer> result = new ArrayList<>();
		
		//진입 차수가 0인 노드를 담을 큐를 선언
		PriorityQueue<Integer> q = new PriorityQueue<>();
		
		for (int i = 1; i <= N; i++) {
			list[i] = new ArrayList<>();
		}
		// 여기서 결과 출력 전까지만 짜면 됨.
		
		for(int i=0;i<E;i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			list[from].add(to);		// from 노드에 to(진출) 노드를 추가한다.
			inDegree[to]++;			// to 노드에 대한 진입 차수를 증가
		}
		//1. 진입 차수가 0인 노드를 찾아 큐에 담기
		for(int i=1;i<=N;i++) {
			if(inDegree[i]==0) q.add(i);
		}
		//2. 큐가 empty가 아닐때까지
		while(!q.isEmpty()) {
			//2.1 진입 차수가 0인 노드를 큐에서 꺼내서 결과에 담는다.
			int cur = q.poll();
			result.add(cur);
			//2.2 진입 차수가 0인 노드에서 진출하는 노드를 방문
			for(int i=0,end = list[cur].size(); i<end;i++) {
				int ad = list[cur].get(i);
				//2.2.1 방문한 노드의 진입을 줄여준다. => 방문한 노드의 진입 차수가 0이면 큐에 담는다.
				if(--inDegree[ad] == 0) q.add(ad);
			}
				
		}
		//3. 결과 출력
		int size = result.size();
		if(size==N) {
			for(int i=0;i<size;i++) {
				System.out.print(result.get(i)+" ");
			}
			System.out.println();
		}else {
			System.out.println("cycle");
		}
		

	}
}
