import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int c = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[] cost = new int[n];
        int[] customer = new int[n];
        int[] dp = new int[c + 101];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            cost[i] = Integer.parseInt(st.nextToken());
            customer[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.fill(dp, (int)1e9);
        dp[0]=0;
        for (int i = 0; i < n; i++) {
            for (int j = customer[i] ; j <= c+100; j++) {
                dp[j] = Math.min(dp[j], dp[j - customer[i]] + cost[i]);
            }
        }
        int ans=(int)1e9;
        for (int i = c; i <= c+100; i++){
            ans = Math.min(ans, dp[i]);
        }
        System.out.println(ans);
    }
}
