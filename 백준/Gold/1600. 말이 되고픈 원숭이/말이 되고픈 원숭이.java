import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Map;
import java.util.StringTokenizer;

public class Main{//_1600_G3_말이_되고픈_원숭이_이현지 {
	static int K, W, H, move, k, ans;
	static int[][] map;
	static boolean[][][] visited;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static int[] hdr = {-2, -2, -1, -1, 1, 1, 2, 2};
    static int[] hdc = {-1, 1, -2, 2, -2, 2, -1, 1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		K = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		
		map = new int[H][W];
		visited = new boolean[K+1][H][W];
		
		for(int i=0; i<H; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<W; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		
		move = 0; k=0; ans = Integer.MAX_VALUE;
		
		System.out.println(bfs(0,0,0,0));
	}

	private static int bfs(int h, int w, int k, int move) {
		Deque<int[]> q = new ArrayDeque<>();
		q.add(new int[] {h, w, k, move});  
		visited[k][h][w] = true;
		
		while(!q.isEmpty()) {
			int[] tmp = q.poll();
			h=tmp[0]; w = tmp[1]; k = tmp[2]; move = tmp[3];
			
			if(h==H-1 && w==W-1) { // 도착
				ans = Math.min(ans, move);
				return ans;
			}
			
			int nh, nw;
			for(int i=0; i<4; i++) {
				nh = h + dr[i];
				nw = w + dc[i];
				if( nh<0 || H-1<nh || nw<0 || W-1<nw || map[nh][nw] == 1 || visited[k][nh][nw] == true) {
					continue;
				}
				visited[k][nh][nw] = true;
				q.add(new int[] {nh, nw, k, move+1});

			}
			if(k < K) {
				for(int i=0; i<8; i++) {
					nh = h + hdr[i];
					nw = w + hdc[i];
					if( nh<0 || H-1<nh || nw<0 || W-1<nw || map[nh][nw] == 1 || visited[k+1][nh][nw] == true) {
						continue;
					}
					visited[k+1][nh][nw] = true;
					q.add(new int[] {nh, nw, k+1, move+1});
				}
			}
		}
		
		return -1;
	}
	
}
