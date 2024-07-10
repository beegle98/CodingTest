import java.io.*;
import java.util.*;

public class Solution {
	static int n, L, ans;
	static int[][] s = new int[22][2];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T = Integer.parseInt(st.nextToken());
		
		for(int tc=1;tc<=T;tc++) {
			StringTokenizer st1 = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st1.nextToken());
			L = Integer.parseInt(st1.nextToken());
			
			for(int i=1;i<=n;i++) {
				StringTokenizer st2 = new StringTokenizer(br.readLine());
				s[i][0] = Integer.parseInt(st2.nextToken());
				s[i][1] = Integer.parseInt(st2.nextToken());
			}
			
			ans=0;
			
			f(0,0,0);
			
			System.out.println("#"+tc+" "+ans);
		}
		
	}
	
	public static void f(int index, int sum, int cal) {
		if(index > n || cal > L) return;
		
		if(ans < sum) ans = sum;
		
		f(index + 1, sum, cal);
		f(index + 1, sum+ s[index+1][0], cal + s[index+1][1]);
	}
}