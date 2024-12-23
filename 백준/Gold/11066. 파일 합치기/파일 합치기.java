import java.io.*;
import java.util.*;

public class Main {
    static final int INF = Integer.MAX_VALUE;
    static int T, n;
    static int[][] cost;
    static int[] sum;

    static int dp(int i, int j) {
        int ret = INF;
        if (i == j) return cost[i][j];
        else if (cost[i][j] != 0) return cost[i][j];
        else {
            for (int k = i; k < j; k++) {
                ret = Math.min(ret, dp(i, k) + dp(k + 1, j) + sum[j + 1] - sum[i]);
            }
            cost[i][j] = ret;
            return ret;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        T = Integer.parseInt(br.readLine());


        for (int k = 0; k < T; k++) {
            n = Integer.parseInt(br.readLine());
            int[] s = new int[n];
            cost = new int[n][n];
            sum = new int[n+1];
            st = new StringTokenizer(br.readLine());

            for (int i = 0; i < n; i++) {
                s[i] = Integer.parseInt(st.nextToken());
            }

            for (int i = 1; i <= n; i++) {
                sum[i] = sum[i-1] + s[i-1];
            }

            for (int i = 0; i < n; i++) {
                Arrays.fill(cost[i], 0);
            }

            System.out.println(dp(0, n-1));
        }

    }
}
