import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
		int[] w = new int[n+1];
		int[] c = new int[n+1];
		int wsum=0, csum=0;
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			w[i] = Integer.parseInt(st.nextToken());
			wsum+=w[i];
		}
		m = wsum-m;
		int[] dp = new int[m+1];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			c[i] = Integer.parseInt(st.nextToken());
			csum+=c[i];
		}	
		for(int i=0;i<n;i++) {
			for(int j=m;j>=w[i];j--) {
				dp[j]=Math.max(dp[j], dp[j-w[i]]+c[i]);
			}
		}
		System.out.println(csum-dp[m]);
    }
}