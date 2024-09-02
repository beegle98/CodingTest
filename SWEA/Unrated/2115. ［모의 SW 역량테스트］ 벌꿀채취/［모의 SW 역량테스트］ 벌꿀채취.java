import java.util.*;
import java.io.*;


public class Solution {
	static int N,M,C, ans;
	static int[][] map;
	//static boolean[][] visited;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(st.nextToken());
		for(int tc=1;tc<=T;tc++) {
			sb.append("#" + tc + " ");
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());
			map = new int[N][N];
			//visited = new boolean[N][N];
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			ans=0;
			for(int i=0;i<N;i++) {
				for(int j=0;j<=N-M;j++) {
					ans = Math.max(ans, solve(i,j));
					
				}
			}
			sb.append(ans + "\n");
		}
		System.out.println(sb.toString());
	}
	private static int getMax(int x,int y,int cnt, int c,int sum) {
		int res=0;
		if(cnt==M || y>=N || c+map[x][y]>C) {
			return sum;
		}
		res = Math.max(res, getMax(x,y+1,cnt+1,c+map[x][y],sum+map[x][y]*map[x][y]));
		res = Math.max(res, getMax(x,y+1,cnt+1,c,sum));
		return res;
	}
	private static int solve(int a, int b) {
		int x=a, y=b;
		int ret=0;
		int sum1 = 0;
		sum1 = getMax(x,y,0,0,0);
		y+=M;
		int sum2 = 0;
		for(int j=y+1;j<=N-M;j++) {
			sum2 = Math.max(sum2, getMax(x,j,0,0,0));
		}
		for(int i=x+1;i<N;i++) {
			for(int j=0;j<=N-M;j++) {
				sum2 = Math.max(sum2, getMax(i,j,0,0,0));
			}
		}
		//System.out.println(sum1 + " " +sum2);
		ret = sum1 + sum2;
		return ret;
	}
	
}
