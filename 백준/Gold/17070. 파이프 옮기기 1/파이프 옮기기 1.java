
import java.util.*;
import java.io.*;

public class Main {
		static int N,ans;
		static int[][] MAP;
		static int[][] dx = {{0,1},{1,1}};
		static int[][] dy = {{1,1},{0,1}};
		static int[][] ds = {{0,2},{1,2}};
		static int[][] cross = {{0,1},{1,0},{1,1}};
		static boolean[][] visited;
		
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	N = Integer.parseInt(st.nextToken());
    	MAP = new int[N][N];
    	visited = new boolean[N][N];
    	for(int i=0;i<N;i++) {
    		st = new StringTokenizer(br.readLine());
    		for(int j=0;j<N;j++) MAP[i][j]=Integer.parseInt(st.nextToken());
    	}
    	ans=0;
    	visited[1][1]=true;
    	dfs(0,1,0);
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
        		if(nx<0 || nx >=N || ny<0 || ny>=N || visited[nx][ny] || MAP[nx][ny]==1) continue;
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
    			if(nx<0 || nx >=N || ny<0 || ny>=N || visited[nx][ny] || MAP[nx][ny]==1) continue;
    			if(i==1 && (MAP[nx-1][ny]==1 || MAP[nx][ny-1]==1)) continue;
    			visited[nx][ny]=true;
    			dfs(nx,ny,ns);
    			visited[nx][ny]=false;
    		}
    	}
    }
}