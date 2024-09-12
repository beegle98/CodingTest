import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
    	int n = Integer.parseInt(st.nextToken());
    	int k = Integer.parseInt(st.nextToken());
    	int[] dp = new int[k+1];
    	int[] w = new int[n];
    	int[] v = new int[n];
    	for (int i = 0; i < n; i++) {
    		st = new StringTokenizer(br.readLine());
    		w[i] = Integer.parseInt(st.nextToken());
    		v[i] = Integer.parseInt(st.nextToken());
    	}
    	for (int i = 0; i < n; i++) {
    		for (int j = k; j >= w[i]; j--) {
    			dp[j] = Math.max(dp[j], dp[j - w[i]] + v[i]);
    		}
    	}
    	System.out.println(dp[k]);
	}
}
