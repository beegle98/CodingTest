import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int MOD = 1000000007;
    static long[][][][] dp = new long[51][51][51][51];

    static long solve(int n, int a,int b, int c) {
        if(n==0){
            if(a==0&&b==0&&c==0) return 1;
            else return 0;
        }
        if(a<0 || b<0 || c<0) return 0;
        if(dp[n][a][b][c]!=-1) return dp[n][a][b][c];

        dp[n][a][b][c]=0;
        dp[n][a][b][c]+=solve(n-1,a-1,b,c);
        dp[n][a][b][c]+=solve(n-1,a,b-1,c);
        dp[n][a][b][c]+=solve(n-1,a,b,c-1);
        dp[n][a][b][c]+=solve(n-1,a-1,b-1,c);
        dp[n][a][b][c]+=solve(n-1,a-1,b,c-1);
        dp[n][a][b][c]+=solve(n-1,a,b-1,c-1);
        dp[n][a][b][c]+=solve(n-1,a-1,b-1,c-1);
        dp[n][a][b][c]%=MOD;

        return dp[n][a][b][c];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        int[] s = new int[3];
        for(int i=0;i<3;i++){
            s[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < 51; i++) {
            for (int j = 0; j < 51; j++) {
                for (int k = 0; k < 51; k++) {
                    for (int l = 0; l < 51; l++) {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        System.out.println(solve(N, s[0], s[1], s[2]));
    }
}
