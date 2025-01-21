import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(st.nextToken());
        //노드 정보를 담을 배열 선언
        List<Integer>[] list = new ArrayList[N+1];
        for (int i = 1; i <= N; i++) {
            list[i] = new ArrayList<>();
        }
        //진입 차수를 위한 배열 선언
        int[] inDegree = new int[N+1];
        int[] cost = new int[N+1];
        int[] dp = new int[N+1];
        for(int i=1;i<=N;i++) {
            st = new StringTokenizer(br.readLine());
            cost[i] = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            for(int j=0;j<M;j++) {
                int from = Integer.parseInt(st.nextToken());
                list[from].add(i);
                inDegree[i]++;
            }

        }
        //진입 차수가 0인 노드를 담을 큐를 선언
        Queue<Integer> q = new LinkedList<>();
        //1. 진입 차수가 0인 노드를 찾아 큐에 담기
        for(int i=1;i<=N;i++) {
            if(inDegree[i]==0){
                q.add(i);
                dp[i]=cost[i];
            }
        }
        //2. 큐가 empty가 아닐때까지
        while(!q.isEmpty()) {
            //2.1 진입 차수가 0인 노드를 큐에서 꺼내서 결과에 담는다.
            int cur = q.poll();
            //2.2 진입 차수가 0인 노드에서 진출하는 노드를 방문
            for(int i=0; i<list[cur].size();i++) {
                int next = list[cur].get(i);
                //2.3 next에 도달하는 시간 중 최댓값을 dp 배열에 저장
                dp[next] = Math.max(dp[next], dp[cur] + cost[next]);
                if(--inDegree[next] == 0){
                    q.add(next);
                }
            }
        }
        //3. 결과 출력
        int ans = 0;
        for(int i=1;i<=N;i++) {
            ans = Math.max(ans, dp[i]);
        }
        System.out.println(ans);
    }

}

