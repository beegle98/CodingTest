import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static long[][] s;
    static long[][][] dp; // (가로: 0, 세로: 1, 대각선: 2)
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        s = new long[N+1][N+1];
        dp = new long[N+1][N+1][3];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                s[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dp[1][2][0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 2; j <= N; j++) {
                if (s[i][j] == 1) continue;
                dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
                dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
                if (s[i - 1][j] == 0 && s[i][j - 1] == 0) {
                    dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
                }
            }
        }
        
        long ans = 0;
        for (int i = 0; i < 3; i++) {
            ans += dp[N][N][i];
        }
        
        System.out.println(ans);
    }
}
