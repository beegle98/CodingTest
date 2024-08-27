import java.util.*;
import java.io.*;

/**
## 위상정렬

- 사이클이 없고 유방향인 그래프에서 진입, 진출 정보를 이용해서 정렬

### 방법

1. 진입 차수가 0인 정점부터 탐색하여 진출하는 정점을 방문해서 연결된 간선을 지운다.
2. 방문한 정점의 진입 차수가 0이면 탐색할 queue에 추가한다.
3. 그래프의 모든 정점을 모두 탐색할 때까지 1~2를 반복
 */
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
		Queue<Integer> q = new LinkedList<>();
		
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
