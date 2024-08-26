
import java.util.*;
import java.io.*;

public class Solution {
	static int N,ans;
	static char[][] MAP;
	static boolean[][] visited;
	static int[] dx = {0,0,-1,1,-1,-1,1,1};
	static int[] dy = {-1,1,0,0,1,-1,1,-1};
	static String str;
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++) {
			N = Integer.parseInt(br.readLine());
			MAP = new char[N][N];
			visited = new boolean[N][N];
			for(int i=0;i<N;i++) {
				str = br.readLine();
				for(int j=0;j<N;j++) {
					MAP[i][j]=str.charAt(j);
				}
			}
			ans=0;
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					if(MAP[i][j]=='.' && Check(i,j)) {
						MAP[i][j]='0';
						dfs(i,j);
						ans++;
					}
				}
			}
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					//System.out.print(MAP[i][j] + " ");
					if(MAP[i][j]=='.') ans++;
				}
				//System.out.println();
			}
			System.out.println("#" + tc + " " + ans);
		}

	}
    private static void dfs(int x, int y) {
		if(!Check(x,y)) {
			MAP[x][y]='1';
			return;
		}
		for(int i=0;i<8;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx<0 || nx >=N || ny<0||ny>=N || visited[nx][ny]) continue;
			MAP[nx][ny]='0';
			visited[nx][ny]=true;
			dfs(nx,ny);
		}
	}
	private static boolean Check(int x,int y) {
    	for(int i=-1;i<=1;i++) {
    		for(int j=-1;j<=1;j++) {
    			if(x+i<0||x+i>=N||y+j<0||y+j>=N) continue;
    			if(MAP[x+i][y+j]=='*') return false;
    		}
    	}
    	return true;
    }
}