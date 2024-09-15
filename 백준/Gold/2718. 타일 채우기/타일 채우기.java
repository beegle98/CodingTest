import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
    	int t = Integer.parseInt(st.nextToken());
    	int[] dp = new int[22];
    	dp[0]=1;
    	dp[1]=1;
    	for(int i=2;i<=21;i++) {
    		dp[i]=dp[i-1]+dp[i-2]*4;
    		for(int j=3;j<=i;j++) {
    			if(j%2==0) dp[i]+=dp[i-j]*3;
    			else dp[i]+=dp[i-j]*2;
    		}
    	}
    	for(int tc=0;tc<t;tc++) {
    		int n = Integer.parseInt(br.readLine());
        	System.out.println(dp[n]);
    	}
	}
}
