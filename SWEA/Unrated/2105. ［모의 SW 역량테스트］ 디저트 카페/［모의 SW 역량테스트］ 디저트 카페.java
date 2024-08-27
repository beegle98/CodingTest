import java.util.*;
import java.io.*;


public class Solution {

	static int N,ans,i,j;
	static int[][] MAP;
	static int[] dx = {1,1,-1,-1};
	static int[] dy = {1,-1,-1,1};
	static boolean[] visited = new boolean[101];
	public static void main(String[] args) throws IOException {
		//입력 받기
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T = Integer.parseInt(st.nextToken());
		for(int tc=1;tc<=T;tc++) {
			N = Integer.parseInt(br.readLine());
			MAP = new int[N][N];
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					MAP[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			ans = -1;
			for(i=0;i<N-2;i++) {
				for(j=1;j<N-1;j++) {
					visited[MAP[i][j]]=true;
					dfs(i+1,j+1,0,1);
					visited[MAP[i][j]]=false;
				}
			}
			System.out.println("#" + tc + " " + ans);
		}
		
	}
	private static void dfs(int x,int y,int d,int sum) {
		if(x==i && y==j) {
			ans = Math.max(ans, sum);
			return;
		}
		if(visited[MAP[x][y]]) return;
		
		visited[MAP[x][y]] = true;
		int nx,ny;
		nx=x+dx[d];
		ny=y+dy[d];
		if(nx>=0 && nx <N && ny>=0 && ny<N) {
			dfs(nx,ny,d,sum+1);
		}
		if(d!=3) {
			d++;
			nx=x+dx[d];
			ny=y+dy[d];
			if(nx>=0 && nx <N && ny>=0 && ny<N) {
				dfs(nx,ny,d,sum+1);
			}
		}
		visited[MAP[x][y]] = false;
	}
}

