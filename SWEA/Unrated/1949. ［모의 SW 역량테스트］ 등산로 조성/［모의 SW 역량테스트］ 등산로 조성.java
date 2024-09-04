import java.io.*;
import java.util.*;

public class Solution {

    static int N,K;
    static int[][] map;
    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};
    static boolean[][] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(st.nextToken());
        
        for (int tc = 1; tc <= T; tc++) {
        	st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            map = new int[N][N];
            visited = new boolean[N][N];
            int max = 0;
            for(int i=0;i<N;i++) {
            	st = new StringTokenizer(br.readLine());
            	for(int j=0;j<N;j++) {
            		map[i][j] = Integer.parseInt(st.nextToken());
            		max = Math.max(max, map[i][j]);
            	}
            }
            int ans=0;
            for(int i=0;i<N;i++) {
            	for(int j=0;j<N;j++) {
            		if(map[i][j]==max) {
            			int ret = dfs(i,j,1,1);
            			ans = Math.max(ans, ret);
            		}
            	}
            }
            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.print(sb.toString());
    }
    static int dfs(int x,int y,int cnt,int key){
    	int res = cnt;
    	visited[x][y]=true;
    	for(int i=0;i<4;i++) {
    		int nx = x + dx[i];
    		int ny = y + dy[i];
    		if(nx<0 || nx >=N || ny<0 || ny>=N || visited[nx][ny]) continue;
    		if(map[nx][ny]<map[x][y]) res = Math.max(res,dfs(nx,ny,cnt+1,key));
    		else if(key==1 && map[nx][ny]-K < map[x][y]) {
    			int tmp = map[nx][ny];
    			map[nx][ny]=map[x][y]-1;
    			res = Math.max(res,dfs(nx,ny,cnt+1,0));
    			map[nx][ny]=tmp;
    		}
    	}
    	visited[x][y]=false;
    	return res;
    }
}

