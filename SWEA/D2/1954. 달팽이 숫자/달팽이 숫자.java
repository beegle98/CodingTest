import java.io.*;
import java.util.*;

public class Solution {

	static int N;
	static int[][] data;
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	public static void dfs(int x,int y,int d,int cnt) {
		if(cnt>N*N) return;
		data[x][y]=cnt;
		int nx = x+dx[d];
		int ny = y+dy[d];
		if(nx < 0 || nx>=N || ny<0 || ny>=N || data[nx][ny]>0) {
			d = (d+1)%4;
			dfs(x+dx[d], y+dy[d], d,++cnt);
		}
		else dfs(nx,ny,d,++cnt);
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc=1;tc<=T;tc++) {
			N = Integer.parseInt(br.readLine());
			data = new int[N][N];
			dfs(0,0,0,1);
			System.out.println("#" + tc);
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					System.out.printf("%d ",data[i][j]);
				}
				System.out.println();
			}
		}
	}

}
