import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Pos{
	int x;
	int y;
	public Pos(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Main {
	static int n,m;
	static int ans = 0;
	static int[][] arr = new int[100][100];
	static boolean[] opened = new boolean[15];

	static List<Pos> chicken = new ArrayList<>();
	static List<Pos> home = new ArrayList<>();
	
	public static void recur(int index, int cnt) {
		if (cnt == m) {
			int sum = 0;
			for (int i = 0; i < home.size(); i++) {
				sum += minDis(home.get(i).x, home.get(i).y);
			}
			ans = min(ans, sum);
		}
		if (index >= chicken.size()) return;
		opened[index] = true;
		recur(index + 1, cnt + 1);
		opened[index] = false;
		recur(index + 1, cnt);
	}
	
	public static int minDis(int x, int y) {
		int MIN = 10000000;
		for (int i = 0; i < chicken.size(); i++) {
			int cx = chicken.get(i).x;
			int cy = chicken.get(i).y;
			if (opened[i]) {
				MIN = min(MIN, Math.abs(x - cx) + Math.abs(y - cy));
			}
		}
		return MIN;
	}
	public static int min(int a,int b) {
		if(a<b) return a;
		return b;
	}
	

	public static void main(String[] args) throws IOException{
		
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		for(int i=1;i<=n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1;j<=n;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j]==1) {
					home.add(new Pos(i,j));
				}else if(arr[i][j]==2) {
					chicken.add(new Pos(i,j));
				}
			}
		}
		ans = 100000000;
		recur(0,0);
		
		System.out.println(ans);
	}

}

