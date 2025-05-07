import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        String[] s = new String[n];
        for(int i=0;i<n;i++) s[i] = br.readLine();
        int[][] dp = new int[n][m];
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = s[i].charAt(j)-'0';
                ans = Math.max(ans,dp[i][j]);
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(dp[i][j]==1) dp[i][j]= Math.min(Math.min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                ans = Math.max(ans,dp[i][j]);
            }
        }
        System.out.println(ans*ans);
    }
}