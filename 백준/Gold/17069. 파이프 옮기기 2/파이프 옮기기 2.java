import java.io.*;
import java.util.*;

public class Main{//_17069_G4_파이프_옮기기_2_이현지 {
    static int n;
    static int[][] map;
    static long[][][] dp;

    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        for(int i = 0; i < n; i++) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dp = new long[n][n][3]; // 가로, 대각선, 세로
        dp[0][1][0]=1;
        dp();
        System.out.println(dp[n-1][n-1][0]+dp[n-1][n-1][1]+dp[n-1][n-1][2]);
    }

	private static void dp() {
		for(int i=0; i<n; i++) {
			for(int j=1; j<n; j++) {
				if(i==0 && j==1) continue;
				if (map[i][j] == 1) continue; // 벽
				dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][1];
				
				if (i == 0) continue;; // -1 불가
				dp[i][j][2] = dp[i-1][j][1] + dp[i-1][j][2];

				if (map[i - 1][j] == 1 || map[i][j - 1] == 1) continue; // 대각선 조건
				dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
			}
		}
	}
}