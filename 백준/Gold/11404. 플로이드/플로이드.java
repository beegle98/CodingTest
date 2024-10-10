import java.io.*;
import java.util.*;

public class Main {

	private final static int INF = (int)1e9; 
    private static int[][] dp;
    private static int N,M;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(br.readLine());
        dp = new int[N+1][N+1];
        
        for(int i=1;i<=N;i++) {
        	Arrays.fill(dp[i], INF);
        	dp[i][i]=0;
        }
        for(int i=0;i<M;i++) {
        	st = new StringTokenizer(br.readLine());
        	int a = Integer.parseInt(st.nextToken()); 
        	int b = Integer.parseInt(st.nextToken()); 
        	int c = Integer.parseInt(st.nextToken());
        	dp[a][b]=Math.min(dp[a][b], c);
        }
    	for(int k=1;k<=N;k++) {
    		for(int i=1;i<=N;i++) {
    			for(int j=1;j<=N;j++) {
    				dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
    			}
    		}
    	}
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				if(dp[i][j]==INF) dp[i][j]=0;
				System.out.print(dp[i][j] + " ");
			}
			System.out.println();
		}
    }
}
