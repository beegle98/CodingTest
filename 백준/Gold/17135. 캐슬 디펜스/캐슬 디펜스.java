
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import javax.management.Query;



public class Main {
	
	
	public static class qPos{
		int x;
		int y;
		int dist;
		public qPos(int x, int y, int dist) {
			this.x = x;
			this.y = y;
			this.dist=dist;
		}
	}
	public static class Pos{
		int x;
		int y;
		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static int dx[] = {0,-1,0}; // 왼쪽 , 위, 오른쪽
	static int dy[] = {-1,0,1};
	static int N,M,D,ans;
	static boolean[] isSelected;
	static int[][] MAP;
	static int[][] OriginMAP;
	static boolean[][] visited;
	static List<Pos> kill = new ArrayList<>();
	static Queue<qPos> q = new LinkedList<>();
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		MAP = new int[N+1][M];
		OriginMAP = new int[N+1][M];
		isSelected = new boolean[M];
		visited = new boolean[N][M];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++) {
				OriginMAP[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		ans=0;
		
		comb(0,0);
		
		System.out.println(ans);
	}
	
	public static void comb(int idx, int cnt) {
		if(cnt == 3) {
			int ret = solve();
			ans = Math.max(ans, ret);
			return;
		}
		if(idx==M) return;
		
		isSelected[idx]=true;
		comb(idx+1,cnt+1);
		isSelected[idx]=false;
		comb(idx+1,cnt);
	}
	
	public static int solve() {
		int cnt=0;
		initMap();
		
		for(int i=0;i<N;i++) {
			kill.clear();
			for(int j=0;j<M;j++) {
				if(isSelected[j]) {
					//System.out.printf("%d ",j);
					initVisited();
					bfs(N-1,j,1);
				}
			}
			//System.out.println();
			for(int j=0;j<kill.size();j++) {
				//System.out.println(MAP[kill.get(j).x][kill.get(j).y]);
				if(MAP[kill.get(j).x][kill.get(j).y]==1) cnt++;
				MAP[kill.get(j).x][kill.get(j).y] = 0;
			}
			if(move()==0) break;
		}
		
		return cnt;
	}
	public static void bfs(int x,int y,int dist) {
		if(dist>D) return;
		if(MAP[x][y]==1) {
			kill.add(new Pos(x,y));
			q.clear();
			return;
		}
		for(int i=0;i<3;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx<0 || nx >=N || ny < 0 || ny >=M || visited[nx][ny]) continue;
			q.add(new qPos(nx,ny,dist+1));
			visited[nx][ny]=true;
		}
		while(!q.isEmpty()) {
			qPos tmp = q.poll();
			bfs(tmp.x, tmp.y,tmp.dist);
		}
	}
	static public int move(){
		int enemyCnt=0;
		//System.out.println();
		for(int j=0;j<M;j++) MAP[N-1][j]=0;
		for(int i=N-2;i>=0;i--) {
			for(int j=0;j<M;j++) {
				//System.out.printf("%d ",MAP[i][j]);
				if(MAP[i][j]==1) {
					enemyCnt++;
					MAP[i][j]=0;
					MAP[i+1][j]=1;
				}
			}
			//System.out.println();
		}
		return enemyCnt;
	}
	public static void initMap() {
		for(int i=0;i<N;i++) {
			MAP[i] = Arrays.copyOf(OriginMAP[i], M);
		}
	}
	public static void initVisited() {
		for(int i=0;i<N;i++) {
			Arrays.fill(visited[i],false);
		}
	}
}

