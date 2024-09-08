import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(st.nextToken());
        for(int tc=1;tc<=T;tc++) {
        	st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            
            int[] w = new int[n];
            int[] dp = new int[10001];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                w[i] = Integer.parseInt(st.nextToken());
            }
            dp[0]=1;
            int m = Integer.parseInt(br.readLine());
           
            for (int i = 0; i < n; i++) {
                for(int j=w[i];j<=m;j++) {
                	dp[j]+=dp[j-w[i]];
                }
            }
            sb.append(dp[m]+"\n");
        }
        System.out.println(sb);
    }
}
