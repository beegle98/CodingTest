import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        
        int[] w = new int[n];
        boolean[] dp = new boolean[40001];
        st = new StringTokenizer(br.readLine());
        int wSum=0;
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(st.nextToken());
            wSum += w[i];
        }
        int m = Integer.parseInt(br.readLine());
        dp[0]=true;
        for (int i = 0; i < n; i++) {
            for (int j = wSum-w[i]; j >= 0; j--) {
                if(dp[j]) dp[j+w[i]] = true;
            }
            for(int j=0;j<=wSum;j++) {
            	if(dp[j]) dp[Math.abs(j-w[i])] = true;
            }
        }
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<m;i++) {
            int x = Integer.parseInt(st.nextToken());
        	if(dp[x]) System.out.print("Y ");
        	else System.out.print("N ");
        }
    }
}
