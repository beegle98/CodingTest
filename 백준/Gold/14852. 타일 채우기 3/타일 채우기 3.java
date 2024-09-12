import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		final long MOD = 1_000_000_007;
		long[] dp= new long[1000001];
		long[] sum = new long[1000001];
		dp[0]=1;
		dp[1]=2;
		dp[2]=7;
		sum[0]=1;
		sum[1]=3;
		sum[2]=10;
		for(int i=3;i<=n;i++) {
			dp[i] = (dp[i]+dp[i-1]*2+dp[i-2]*3+sum[i-3]*2)%MOD;
			sum[i] = (sum[i-1] + dp[i])%MOD;
		}
		System.out.println(dp[n]);
	}
}
