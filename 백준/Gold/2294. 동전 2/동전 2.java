import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        final int INF = (int)1e9;
        int[] arr = new int[N];
        int[] dp = new int[K+1];
        Arrays.fill(dp,INF);
        for(int i=0;i<N;i++) arr[i] = Integer.parseInt(br.readLine());
        dp[0]=0;
        for (int i = 0; i < N; i++){
    		for (int j = arr[i]; j <= K; j++){
    			dp[j] = Math.min(dp[j], dp[j-arr[i]]+1);
    		}
    	}
        if(dp[K]==INF) System.out.println("-1");
        else System.out.println(dp[K]);
    }
}