import java.io.*;
import java.util.*;

public class Main {

    static int[][] dp = new int[50001][4];
    static int[] sum = new int[50001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=1;i<=n;i++) {
            int a = Integer.parseInt(st.nextToken());
            sum[i] = sum[i - 1] + a;
        }
        int k = Integer.parseInt(br.readLine());
        for(int i=k;i<=n;i++) {
            int pSum = sum[i]-sum[i-k];
            dp[i][1]=Math.max(dp[i-1][1],pSum);
            if(dp[i-k][1]>0) dp[i][2]=Math.max(dp[i-1][2],dp[i-k][1]+pSum);
            if(dp[i-k][2]>0) dp[i][3] = Math.max(dp[i-1][3],dp[i-k][2]+pSum);
        }
        System.out.println(dp[n][3]);
    }
}
