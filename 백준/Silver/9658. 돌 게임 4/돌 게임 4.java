import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        boolean[] dp = new boolean[1001];
        dp[1] = dp[3] = false;
        dp[2] = dp[4] = dp[5] = true;
        for(int i=6;i<=n;i++) dp[i] = !(dp[i-1] && dp[i-3] && dp[i-4]);
        if(dp[n]) System.out.println("SK");
        else System.out.println("CY");
    }
}