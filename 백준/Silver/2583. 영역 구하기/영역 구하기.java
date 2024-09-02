import java.util.*;
import java.io.*;
public class Main {

	static int N,M,K;
	static int[][] map;
	static int[] dx = {0,0,-1,1};
	static int[] dy = {-1,1,0,0};
	static ArrayList<Integer> ans = new ArrayList<>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		map = new int[N+1][M+1];
		for(int i=0;i<K;i++) {
			st = new StringTokenizer(br.readLine());
			int x1,x2,y1,y2;
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());
			SetMap(x1,y1,x2-1,y2-1);
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j]==0) {
					int ret = dfs(i,j);
					ans.add(ret);
				}
			}
		}
		Collections.sort(ans);
		System.out.println(ans.size());
		for(int a : ans) {
			System.out.print(a + " ");
		}
		System.out.println();
	}
	private static int dfs(int x, int y) {
		
		map[x][y]=1;
		int res=1;
		for(int i=0;i<4;i++) {
			int nx,ny;
			nx = x+dx[i];
			ny = y+dy[i];
			if(nx<0 || nx >=N || ny<0 || ny>=M ||map[nx][ny]==1) continue;
			res+=dfs(nx,ny);
		}
		return res;
	}
	private static void SetMap(int x1, int y1, int x2, int y2) {
		for(int i=x1;i<=x2;i++) {
			for(int j=y1;j<=y2;j++) map[i][j]=1;
		}
		
	}

}