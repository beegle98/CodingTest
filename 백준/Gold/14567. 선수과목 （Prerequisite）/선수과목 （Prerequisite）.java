import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        //노드 정보를 담을 배열 선언
        List<Integer>[] list = new ArrayList[N+1];
        for (int i = 1; i <= N; i++) {
            list[i] = new ArrayList<>();
        }

        //진입 차수를 위한 배열 선언
        int[] inDegree = new int[N+1];
        //결과 배열 선언
        int[] ans = new int[N+1];

        //진입 차수가 0인 노드를 담을 큐를 선언
        Queue<Integer> q = new LinkedList<>();

        for(int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            list[from].add(to);		// from 노드에 to(진출) 노드를 추가한다.
            inDegree[to]++; 		// to 노드에 대한 진입 차수를 증가
        }
        //1. 진입 차수가 0인 노드를 찾아 큐에 담기
        for(int i=1;i<=N;i++) {
            if(inDegree[i]==0){
                q.add(i);
                ans[i]=1;
            }
        }
        //2. 큐가 empty가 아닐때까지
        while(!q.isEmpty()) {
            //2.1 진입 차수가 0인 노드를 큐에서 꺼내서 결과에 담는다.
            int cur = q.poll();
            //2.2 진입 차수가 0인 노드에서 진출하는 노드를 방문
            for(int i=0; i<list[cur].size();i++) {
                int next = list[cur].get(i);
                //2.2.1 방문한 노드의 진입을 줄여준다. => 방문한 노드의 진입 차수가 0이면 큐에 담고 이전 노드의 결과 + 1 을 넣어준다.
                if(--inDegree[next] == 0){
                    q.add(next);
                    ans[next]=ans[cur]+1;
                }
            }
        }
        //3. 결과 출력
        for(int i=1;i<=N;i++) {
            sb.append(ans[i]).append(" ");
        }
        System.out.println(sb);
    }

}

