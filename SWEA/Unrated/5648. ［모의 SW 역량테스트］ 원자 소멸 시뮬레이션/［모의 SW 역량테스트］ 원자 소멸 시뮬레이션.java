import java.io.*;
import java.util.*;
 
public class Solution {
	static class Atom{
		int x,y;
		int dir;
		int energy;
		public Atom(int x, int y, int dir, int energy) {
			super();
			this.x = x;
			this.y = y;
			this.dir = dir;
			this.energy = energy;
		}
	}
    static int N,X,ans;
    static int map[][] = new int[4001][4001];
    static List<Atom> list = new ArrayList<>();
    static int dx[] = {0,0,-1,1};
    static int dy[] = {1,-1,0,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(st.nextToken());
        for (int tc = 1; tc <= T; tc++) {
        	st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                int x = (Integer.parseInt(st.nextToken()) + 1000) * 2;
                int y = (Integer.parseInt(st.nextToken()) + 1000) * 2;
                int dir = Integer.parseInt(st.nextToken());
                int energy = Integer.parseInt(st.nextToken());
                list.add(new Atom(x,y,dir,energy));
            }
            int ans=solve();

            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.print(sb.toString());
    }
	private static int solve() {
		int sum = 0;
		while(!list.isEmpty()) {
			for(int i=0;i<list.size();i++) {
				Atom a = list.get(i);
				map[a.x][a.y]=0;
				a.x += dx[a.dir];
				a.y += dy[a.dir];
				if (a.x > 4000 || a.x < 0 || a.y > 4000 || a.y < 0) {
					list.remove(i);
					i--;
					continue;
				}
				map[a.x][a.y]+=a.energy;
			}
			for(int i=0;i<list.size();i++) {
				Atom a = list.get(i);
				if (map[a.x][a.y]!=a.energy) {
					sum+=map[a.x][a.y];
					map[a.x][a.y]=0;
					list.remove(i);
					i--;
				}
			}
		}
		return sum;
	}
}
