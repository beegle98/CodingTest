
import java.util.*;
import java.io.*;

public class Main {
		static int N;
		static long ans;
		static int[][] MAP;
		static int[][] dx = {{0,1},{1,1}};
		static int[][] dy = {{1,1},{0,1}};
		static int[][] ds = {{0,2},{1,2}};
		static int[][] cross = {{0,1},{1,0},{1,1}};
		static boolean[][] visited;
		static long[][][] dp = new long[40][40][3];//x,y,모양 (가로:0, 세로:1, 대각선:2)
		
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	N = Integer.parseInt(st.nextToken());
    	MAP = new int[N+1][N+1];
    	visited = new boolean[N+1][N+1];
    	for(int i=1;i<=N;i++) {
    		st = new StringTokenizer(br.readLine());
    		for(int j=1;j<=N;j++) MAP[i][j]=Integer.parseInt(st.nextToken());
    	}
    	ans=0;
    	//visited[1][1]=true;
    	//dfs(0,1,0);
    	ans = dp();
    	System.out.println(ans);
    }
    // stat : 0=가로, 1=세로, 2=대각선
    private static void dfs(int x,int y,int stat) {
    	if(x==N-1 && y==N-1) {
    		ans++;
    		return;
    	}
    	int nx,ny,ns;
    	//대각선
    	
    	if(stat==2) {
        	for(int i=0;i<3;i++) {
        		nx = x + cross[i][0];
        		ny = y + cross[i][1];
        		if(nx<1 || nx >N || ny<1 || ny>N || visited[nx][ny] || MAP[nx][ny]==1) continue;
        		if(i==2 && (MAP[nx-1][ny]==1 || MAP[nx][ny-1]==1)) continue;
        		visited[nx][ny]=true;
        		dfs(nx,ny,i);
        		visited[nx][ny]=false;
        	}
    	}else {
    		for(int i=0;i<2;i++) {
    			nx = x+dx[stat][i];
    			ny = y+dy[stat][i];
    			ns = ds[stat][i];
    			if(nx<1 || nx >N || ny<1 || ny>N || visited[nx][ny] || MAP[nx][ny]==1) continue;
    			if(i==1 && (MAP[nx-1][ny]==1 || MAP[nx][ny-1]==1)) continue;
    			visited[nx][ny]=true;
    			dfs(nx,ny,ns);
    			visited[nx][ny]=false;
    		}
    	}
    }
    private static long dp() {
    	dp[1][2][0] = 1;
    	for (int i = 1; i <= N; i++) {
    		for (int j = 1; j <= N; j++) {
    			if (MAP[i][j] == 1) continue;
    			dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
    			dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
    			if (MAP[i - 1][j] == 0 && MAP[i][j - 1] == 0) {
    				for (int k = 0; k < 3; k++) dp[i][j][2] += dp[i - 1][j - 1][k];
    			}
    		}
    	}
    	long res = 0;
    	for (int i = 0; i < 3; i++) {
    		res += dp[N][N][i];
    	}
    	return res;
    }
}