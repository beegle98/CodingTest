
import java.io.*;
import java.util.*;

public class Main {

	private static class Pos{
		int x,y;
		int depth;
		public Pos(int x, int y, int depth) {
			super();
			this.x = x;
			this.y = y;
			this.depth = depth;
		}
	}
    private static char[][] map;
    private static int[][] Depth;
    private static int[] end = new int [2];
    private static int N,M;
    private static Queue<Pos> wq = new LinkedList<>();
    private static Queue<Pos> q = new LinkedList<>();
    private static int[] dx = {0,0,-1,1};
    private static int[] dy = {-1,1,0,0};
    private static boolean[][] visited;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		map = new char[N][M];
		Depth= new int[N][M];
		visited = new boolean[N][M];
		
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for(int j=0;j<M;j++) {
				map[i][j]=str.charAt(j);
				if(map[i][j]=='*') wq.add(new Pos(i,j,0));
				else if(map[i][j]=='S') {
					q.add(new Pos(i,j,0));
					visited[i][j]=true;
				}else if(map[i][j]=='D') {
					end[0]=i;
					end[1]=j;
				}else if(map[i][j]=='.') {
					Depth[i][j]=Integer.MAX_VALUE;
				}
			}
		}

		bfs_w();
		int ans=bfs_s();
		if(ans==-1) System.out.println("KAKTUS");
		else System.out.println(ans);
    }
	private static void bfs_w() {
		while(!wq.isEmpty()) {
			Pos cur = wq.poll();
			
			for(int i=0;i<4;i++) {
				int nx = cur.x+dx[i];
				int ny = cur.y+dy[i];
				if(nx<0 || nx >=N || ny<0 || ny>=M || map[nx][ny]!='.' || Depth[nx][ny]<=cur.depth+1) continue;
				Depth[nx][ny]=cur.depth+1;
				wq.add(new Pos(nx,ny,cur.depth+1));
			}	
		}
	}
	private static int bfs_s() {
		int len=-1;
		
		while(!q.isEmpty()) {
			Pos cur = q.poll();
			for(int i=0;i<4;i++) {
				int nx = cur.x+dx[i];
				int ny = cur.y+dy[i];
				if(nx==end[0] && ny==end[1]) return cur.depth+1;
				if(nx<0 || nx >=N || ny<0 || ny>=M || map[nx][ny]!='.' || visited[nx][ny] || Depth[nx][ny]<=cur.depth+1) continue;
				visited[nx][ny]=true;
				q.add(new Pos(nx,ny,cur.depth+1));
			}	
		}
		return len;
	}
}

