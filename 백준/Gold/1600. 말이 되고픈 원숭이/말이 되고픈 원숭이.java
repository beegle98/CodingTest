import java.io.*;
import java.util.*;
 
public class Main {
    static int N, M, K;
    static int[][] MAP;
    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};
    static int[] hx = {-2,-2,-1,-1,1,1,2,2};
    static int[] hy = {-1,1,-2,2,-2,2,-1,1};
    static int ans;
    static boolean[][][] visited;
    public static void main(String[] args) throws IOException {
         
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		MAP = new int[N][M];
		visited = new boolean[N][M][K+1];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++)
				MAP[i][j] = Integer.parseInt(st.nextToken());
		}
		ans=-1;
		bfs();
		System.out.println(ans);
    }
    private static class Pos{
    	int x;
    	int y;
    	int cnt;
    	int horse;
		public Pos(int x, int y, int cnt, int horse) {
			this.x = x;
			this.y = y;
			this.cnt = cnt;
			this.horse = horse;
		}
    }
    private static void bfs() {
    	Queue<Pos> q = new LinkedList<>();
    	q.add(new Pos(0,0,0,0));
    	visited[0][0][0]=true;
    	while(!q.isEmpty()){
    		Pos cur = q.poll();
    		if(cur.x==N-1 && cur.y==M-1) {
    			ans = cur.cnt;
    			q.clear();
    			break;
    		}
    		for(int i=0;i<8;i++) {
    			if(cur.horse==K) break;
    			int nx = cur.x + hx[i];
    			int ny = cur.y + hy[i];
    			if(nx<0||nx>=N||ny<0||ny>=M|| MAP[nx][ny]==1||visited[nx][ny][cur.horse+1]) continue;
    			visited[nx][ny][cur.horse+1]=true;
    			q.add(new Pos(nx,ny,cur.cnt+1,cur.horse+1));
    		}
    		for(int i=0;i<4;i++) {
    			int nx = cur.x + dx[i];
    			int ny = cur.y + dy[i];
    			if(nx<0||nx>=N||ny<0||ny>=M||MAP[nx][ny]==1||visited[nx][ny][cur.horse]) continue;
    			visited[nx][ny][cur.horse]=true;
    			q.add(new Pos(nx,ny,cur.cnt+1,cur.horse));
    		}
    	}
    }
}