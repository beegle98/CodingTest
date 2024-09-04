import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int[][] cost = new int[N][N];
        for(int i=0;i<N;i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j=0;j<N;j++) {
        		cost[i][j]= Integer.parseInt(st.nextToken());
        	}
        }
        int[][] dp = new int[N][1<<N];
        int INF = Integer.MAX_VALUE;
        for(int[] i : dp) Arrays.fill(i, INF);
        for(int i=0;i<N;i++) dp[0][1<<i]=cost[0][i];
        for(int i=1;i<N;i++) {
        	for(int j=0;j<1<<N;j++) {
        		if(dp[i-1][j]==INF) continue;
        		for(int k=0;k<N;k++) {
        			if((j & 1<<k) != 0) continue;
        			dp[i][j|1<<k]=Math.min(dp[i][j|1<<k], dp[i-1][j] +cost[i][k]);
        		}
        	
        	}
        }
        int ans = dp[N-1][(1<<N)-1];
        System.out.println(ans);
    }
    
}