import java.io.*;
import java.util.*;

public class Solution {

    static int N,M,ans;
    static ArrayList<Integer>[][] list;
    static boolean[] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(st.nextToken());
        
        for (int tc = 1; tc <= T; tc++) {
        	
            N = Integer.parseInt(br.readLine());
            M = Integer.parseInt(br.readLine());
            list = new ArrayList[2][N+1];
            visited = new boolean[N+1];
            for(int i=0;i<2;i++) {
            	for(int j=0;j<=N;j++) list[i][j] = new ArrayList<>();

            }
            for(int i=0;i<M;i++) {
            	st = new StringTokenizer(br.readLine());
            	int a,b;
            	a = Integer.parseInt(st.nextToken()); 
            	b = Integer.parseInt(st.nextToken());
            	list[0][a].add(b);
            	list[1][b].add(a);
            }
            ans=0;
            for(int i=1;i<=N;i++) {
            	Arrays.fill(visited, false);
            	int up = dfs(0,i);
            	Arrays.fill(visited, false);
            	int down = dfs(1,i);
            	//System.out.println(up + " " + down);
            	if(up+down==N+1) ans++;
            }
            
            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.print(sb.toString());
    }

	private static int dfs(int flag, int idx) { // flag : 0=up, 1=down
		int cnt=1;
		for(int i=0;i<list[flag][idx].size();i++) {
			int next = list[flag][idx].get(i);
			if(visited[next]) continue;
			visited[next]=true;
			cnt+=dfs(flag,next);
		}
		
		return cnt;
	}
    
}
