import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(st.nextToken());

		int[] w = new int[4];
		int[] num = {1,5,10,25};
		int[][] dp = new int[10001][5];
		for (int i = 0; i < 4; i++) {
			w[i] = Integer.parseInt(st.nextToken());
		}
		for(int i=0;i<=n;i++) Arrays.fill(dp[i], -1);
		for(int i=0;i<=4;i++) dp[0][i]=0;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 4; j++) {
				if(dp[i][j]==-1)dp[i][j] = 0;
				if (i - num[j] < 0)continue;
				if (dp[i - num[j]][4] > dp[i][4]) {				
					if (w[j] >= (dp[i - num[j]][j] + 1)) {
						for (int k = 0; k < 4; k++)
							dp[i][k] = dp[i - num[j]][k];
						dp[i][4] = dp[i - num[j]][4] + 1;
						dp[i][j] += 1;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++) sb.append(dp[n][i] + " ");
		System.out.println(sb);

	}
}
