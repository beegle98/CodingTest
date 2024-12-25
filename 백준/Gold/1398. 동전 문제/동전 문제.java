import java.io.*;
import java.util.*;

public class Main {
    static long[] dp = new long[101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());
        for(int t=0;t<T;t++) {
            st = new StringTokenizer(br.readLine());
            long N = Long.parseLong(st.nextToken());
            for(int i=1;i<101;i++){
                dp[i] = dp[i-1] + 1;
                if(i>=10) dp[i] = Math.min(dp[i], dp[i-10]+1);
                if(i>=25) dp[i] = Math.min(dp[i], dp[i-25]+1);
            }
            long ans=0;
            while(N>0){
                int k = (int)(N%100);
                N/=100;
                ans += dp[k];
            }
            System.out.println(ans);
        }
    }
}
