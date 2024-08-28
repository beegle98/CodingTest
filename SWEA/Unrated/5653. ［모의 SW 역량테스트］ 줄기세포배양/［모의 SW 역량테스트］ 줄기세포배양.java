import java.util.*;
import java.io.*;

public class Solution {
	private static class Cell implements Comparable<Cell>{
		int x;
		int y;
		int hp;
		int	deathTime;
		int actived; // 0 = 비활성 , 1 = 활성, -1 = 번식 후 남은 상태
		
		public Cell(int x, int y, int hp, int time, int actived) {
			super();
			this.x = x;
			this.y = y;
			this.hp = hp;
			this.deathTime = time;
			this.actived = actived;
		}

		@Override
		public int compareTo(Cell o) {
			if(this.deathTime != o.deathTime) return this.deathTime - o.deathTime;
			return o.hp - this.hp;
		}
		
	}
	static int N,M,K;
	static int[][] visited;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};	
	static PriorityQueue<Cell> pq = new PriorityQueue<>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
		
		for(int tc=1;tc<=T;tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			visited = new int[N+K+1][M+K+1];
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<M;j++) {
					int x = Integer.parseInt(st.nextToken());
					if(x!=0) {
						visited[i+K/2][j+K/2]=x;
						pq.add(new Cell(i+K/2,j+K/2,x,x,0));
					}
				}
			}
			bfs();
			System.out.println("#" + tc + " " + pq.size());
			pq.clear();
		}
		
	}
	private static void bfs() {
		int curTime=0;
		while(!pq.isEmpty()) {
			if(curTime==K+1) return;
			Cell cur = pq.peek();
			if(cur.deathTime>curTime) {
				curTime++;
				continue;
			}
			Cell tmp = cur;
			while(!pq.isEmpty() && tmp.deathTime==curTime) {
				tmp = pq.poll();
				if(tmp.actived==1) {
					active(tmp,curTime);
					pq.add(new Cell(tmp.x,tmp.y,tmp.hp,curTime+tmp.hp-1,-1));
				}else if(tmp.actived==0) {
					pq.add(new Cell(tmp.x,tmp.y,tmp.hp,curTime+1,1));
				}
				tmp = pq.peek();
			}
			curTime++;
		}
	}
	private static void active(Cell cur, int curTime) {
		int nx,ny;
		for(int i=0;i<4;i++) {
			nx= cur.x+dx[i];
			ny= cur.y+dy[i];
			if(visited[nx][ny]==0) {
				visited[nx][ny]=cur.hp;
				pq.add(new Cell(nx,ny,cur.hp,curTime+cur.hp,0));
			}
		}
	}
}