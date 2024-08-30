import java.io.*;
import java.util.*;
/*
91,496 kb
메모리
561 ms
실행시간
 */
public class Solution {

	static int N,L,ans;
	static ArrayList<Integer>[] list = new ArrayList[2]; // 0 = 0번째, 1 = 1번째 계단과의 거리
	static int[][] MAP;
	static int[] num;
	static int[] k = new int[2];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for(int tc=1;tc<=T;tc++) {
			sb.append("#" + tc + " ");
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			MAP = new int[N][N];
			
			ArrayList<Integer>[] stair = new ArrayList[2];
			stair[0] = new ArrayList<>();
			stair[1] = new ArrayList<>();
			int cnt=0;
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					MAP[i][j] = Integer.parseInt(st.nextToken());
					if(MAP[i][j]>1) {
						k[cnt++] = MAP[i][j];
						stair[0].add(i);
						stair[1].add(j);
					}
				}
			}
			list[0] = new ArrayList<>();
			list[1] = new ArrayList<>();
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					if(MAP[i][j]==1) {
						for(int t=0;t<2;t++) {
							list[t].add(Math.abs(i-stair[0].get(t))+Math.abs(j-stair[1].get(t)));
						}
					}
				}
			}
			L = list[0].size();
			ans = Integer.MAX_VALUE;
			num = new int[L];
			subset(0);
			sb.append(ans + "\n");
		}
		System.out.println(sb.toString());
	}
	private static void subset(int depth) {
		if(depth==L) {
			int ret = solve();
			ans = Math.min(ans, ret);
			return;
		}
		num[depth]=0;
		subset(depth+1);
		num[depth]=1;
		subset(depth+1);
	}
	private static int solve() {
		PriorityQueue<Integer>[] pq = new PriorityQueue[2];
		pq[0] = new PriorityQueue<>();
		pq[1] = new PriorityQueue<>();
		for(int i=0;i<L;i++) {
			int n = num[i];
			//System.out.print(num[i] + " ");
			pq[n].add(list[n].get(i));
		}
		int res = 0;
		for(int i=0;i<2;i++) {
			LinkedList<Integer> q = new LinkedList<>();
			int waitTime=0; // 대기 시간
			while(!pq[i].isEmpty()) {
				if(q.size()<3) {
					q.add(pq[i].poll()+1+k[i]);
				}else {
					int next = pq[i].peek();
					if(next>q.peek()) {
						while(!q.isEmpty() && next>q.peek()) q.poll();
					}else {
						int add=0;
						if(next==q.peek()) add=1;
						next = pq[i].poll();
						waitTime = q.poll() - next;
						q.add(next+k[i]+add+waitTime);
					}
				}
			}
			int last=0;
			while(!q.isEmpty()) {
				last = q.poll();
			}
			res = Math.max(res, last);
		}
		//System.out.println(res);
		return res;
	}
}