import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        final int MOD = 1_000_000_000; 
        int[][][] dp = new int[N+1][10][1024];
        for(int i=1;i<10;i++) dp[1][i][1<<i]=1;
        for(int i=2;i<=N;i++) {
        	for(int j=0;j<10;j++) {
        		for(int k=0;k<1024;k++) {
        			if(j-1>=0) dp[i][j][k | 1<<j] = (dp[i][j][k | 1<<j]+dp[i-1][j-1][k])%MOD;
        			if(j+1<=9) dp[i][j][k | 1<<j] = (dp[i][j][k | 1<<j]+dp[i-1][j+1][k])%MOD;
        		}
        	}
        }
        int ans = 0;
        for(int i=0;i<10;i++) {
        	ans = (ans + dp[N][i][1023])%MOD;
        }
        System.out.println(ans);
    }
    
}