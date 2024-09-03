import java.io.*;
import java.lang.*;
import java.util.*;

/*
 * 306012kb	1220ms
 */

public class Main{//_4485_G4_녹색_옷_입은_애가_젤다지_이현지 {
    static int N, ans;//, rob;
    static int[][] map;
    static int[] dr = {-1,1,0,0}, dc = {0,0,-1,1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        N = Integer.parseInt(br.readLine());
        int t=0;
        while(N!=0) {
        	t++;
        	sb.append("Problem ").append(t).append(": ");
        	map = new int[N][N];
            StringTokenizer st;
            for(int i=0; i<N; i++) {
            	st = new StringTokenizer(br.readLine());
            	for(int j=0; j<N; j++) {
            		map[i][j] = Integer.parseInt(st.nextToken());
            	}
            }
            ans = getMinRob(0, 0, N-1, N-1);
            sb.append(ans).append("\n");
            N = Integer.parseInt(br.readLine());
        }
        System.out.println(sb);
    }

	private static int getMinRob(int sr, int sc, int er, int ec) {
		boolean[][] visited = new boolean[N][N];
		final int INF = Integer.MAX_VALUE;
		int[][] minRob = new int[N][N];
		PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->Integer.compare(a[2], b[2]));
		
		for(int i=0; i<N; i++) {
			Arrays.fill(minRob[i], INF);
		}
		
		minRob[sr][sc] = map[0][0];
		pq.offer(new int[] {sr,sc,minRob[sr][sc]});
		
		while(!pq.isEmpty()) {
			int[] o = pq.poll();
			int r = o[0];
			int c = o[1];
			int rob = o[2];
			
			if(visited[r][c]) continue;
			visited[r][c] = true;
			if(r == er && c == ec) {
//				for(int i=0; i<N; i++) {
//					for(int j=0; j<N; j++) {
//						System.out.print(minRob[i][j]+" ");
//					}
//					System.out.println();
//				}
//				System.out.println(rob);
				return rob; // 도착
			}
			for(int d = 0; d<4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if( 0 <= nr && nr < N && 0 <= nc && nc < N && !visited[nr][nc] && minRob[nr][nc] > rob + map[nr][nc]) {
					minRob[nr][nc] = rob + map[nr][nc];
					pq.offer(new int[] {nr, nc, minRob[nr][nc]});
				}
			}
		}
		return INF;
		
	}
}

