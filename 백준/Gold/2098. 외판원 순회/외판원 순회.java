import java.io.*;
import java.util.*;

public class Main {

    private static final int MAX = 1 << 16;
    private static final int INF = 987654321;

    private static int[][] w = new int[20][20];
    private static int n, fullBit;
    private static int[][] dp = new int[20][MAX];

    private static int dfs(int cur, int visited) {
        if (visited == fullBit) {
            if (w[cur][0] != 0) {
                return w[cur][0];
            } else {
                return INF;
            }
        }

        if (dp[cur][visited] != -1) return dp[cur][visited];

        dp[cur][visited] = INF;
        for (int i = 0; i < n; i++) {
            if (w[cur][i] == 0 || (visited & (1 << i)) != 0) continue;
            dp[cur][visited] = Math.min(dp[cur][visited], w[cur][i] + dfs(i, visited | (1 << i)));
        }

        return dp[cur][visited];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        fullBit = (1 << n) - 1;

        for (int[] i : dp) {
            java.util.Arrays.fill(i, -1);
        }

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                w[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int ans = dfs(0,1);
        System.out.println(ans);
    }
}
