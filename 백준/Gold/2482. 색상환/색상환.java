
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		final int MOD = (int)1e9+3;
		int ans;
		int[][] dp = new int[n+1][k+1];
		for(int i=1;i<=n;i++) {
			dp[i][1]=i;
			dp[i][0]=1;
		}
		for(int i=2;i<=n;i++) {
			for(int j=2;j<=k;j++) {
				dp[i][j] = (dp[i-1][j] + dp[i-2][j-1])%MOD;
			}
		}
		System.out.println((dp[n-1][k] + dp[n-3][k-1])%MOD);

	}

}
