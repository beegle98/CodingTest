import java.io.*;
import java.util.*;

public class Solution {

	static int[] Num;
	static int N,T,Ans;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		
		for(int tc=1;tc<=t;tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			T = Integer.parseInt(st.nextToken());
			Num = new int[N];
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++) {
				Num[i] = Integer.parseInt(st.nextToken());
			}
			Ans = Integer.MAX_VALUE;
			recur(0,0);
			System.out.printf("#%d %d\n",tc,Ans-T);
		}
		
	}
	public static void recur(int cnt,int sum) {
		if(sum>=T) {
			Ans = Math.min(Ans, sum);
			return;
		}
		if(cnt==N) return;
		recur(cnt+1,sum+Num[cnt]);
		recur(cnt+1,sum);
	}
	
}
