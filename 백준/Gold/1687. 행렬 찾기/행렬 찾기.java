import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] arr = new int[n+1][m+1];
        int[][] dp = new int[n+1][m+1];
        for(int i=1;i<=n;i++){
            String str = br.readLine();
            for(int j=1;j<=m;j++){
                arr[i][j] = str.charAt(j-1)-'0';
                dp[i][j] = dp[i][j-1]+arr[i][j];
            }
        }
        int ans = 0;
        for(int i=1;i<=m;i++){
            for(int j=i;j<=m;j++){
                int sum = 0;
                for(int k=1;k<=n;k++){
                    if(dp[k][j] - dp[k][i-1]==0) sum+=j-i+1;
                    else sum = 0;
                    ans = Math.max(ans,sum);
                }
            }
        }
        System.out.println(ans);
    }
}