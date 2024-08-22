import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 메모리 : 31,168kb
 * 실행시간 : 159ms
 */
public class Solution {
	static int N;
	static int[][] MAP;
	static boolean[][] visited;
	static int Min, Max;
	static int[] dx= {0,0,1,-1};
	static int[] dy= {1,-1,0,0};
	

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int T = Integer.parseInt(st.nextToken());

		for (int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			MAP = new int[N][N];
			visited = new boolean[N][N];
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					MAP[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			Max = 0;
			Min = Integer.MAX_VALUE;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (!visited[i][j]) solve(i,j);
				}
			}
			System.out.println("#" + tc + " " + Min + " " + Max);
		}
	}
	private static void solve(int x,int y) {
		int cnt = dfsUp(x,y,1);
		dfsDown(x,y,cnt);
	}
	
	private static int dfsUp(int x,int y, int cnt) {
		visited[x][y]=true;
		for(int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >=0 && nx < N && ny >=0 && ny < N
					&& !visited[nx][ny] && MAP[x][y] + 1 == MAP[nx][ny]) {
				return dfsUp(nx,ny,cnt+1);
			}
		}
		return cnt;
	}
	private static void dfsDown(int x,int y,int cnt) {
		visited[x][y]=true;
		for(int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >=0 && nx < N && ny >=0 && ny < N
					&& !visited[nx][ny] && MAP[x][y] - 1 == MAP[nx][ny]) {
				dfsDown(nx,ny,cnt+1);
				return;
			}
		}
		if(cnt>Max) {
			Max = cnt;
			Min = MAP[x][y];
		}else if(cnt==Max) {
			Min = Math.min(Min, MAP[x][y]);
		}
	}
}
