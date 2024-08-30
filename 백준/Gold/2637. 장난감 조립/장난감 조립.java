import java.util.*;
import java.io.*;

public class Main {
	
	static int N,M;
	static long[][] dp;
	static int[][] map;
	static int[] outDegree;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		dp = new long[N+1][N+1];
		map = new int[N+1][N+1];
		outDegree = new int[N+1];
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int a,b,c;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			outDegree[a]++;
			map[a][b] = c;
		}
		for(int i=1;i<N;i++) {
			if(outDegree[i]==0) {
				dp[i][0]=1;
				dp[i][i]=1;
			}
		}
		recur(N);
		for(int i=1;i<N;i++) {
			if(outDegree[i]==0) {
				System.out.println(i + " " + dp[N][i]);
			}
		}
	}
	private static long[] recur(int idx) {
		if(dp[idx][0]>0) return dp[idx];
		for(int i=1;i<N;i++) {
			int cnt = map[idx][i];
			if(cnt>0) {
				long[] tmp = recur(i);
				for(int j=0;j<N;j++) {
					dp[idx][j] += cnt * tmp[j];
				}
			}
		}
		return dp[idx];
	}
}
