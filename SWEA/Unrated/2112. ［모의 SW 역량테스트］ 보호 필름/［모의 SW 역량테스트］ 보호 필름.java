import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int N, M, K, S_len;
	static int[][] MAP;
	static int Min;
	static int[] Selected1, Selected2;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int T = Integer.parseInt(st.nextToken());

		for (int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			MAP = new int[N][M];
			Selected1 = new int[N];
			Selected2 = new int[N];
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < M; j++)
					MAP[i][j] = Integer.parseInt(st.nextToken());
			}
			Min = Integer.MAX_VALUE;
			subset1(0, 0);
			System.out.println("#" + tc + " " + Min);
		}

	}

	private static void subset1(int cnt, int len) {
		if (len >= Min)
			return;
		if (cnt == N) {
			S_len = len;
			subset2(0);
			return;
		}
		subset1(cnt + 1, len);
		Selected1[len] = cnt;
		subset1(cnt + 1, len + 1);
	}

	private static void subset2(int cnt) {
		if (cnt == S_len) {
			int[][] tmp = new int[N][M];
			for (int i = 0; i < N; i++) {
				tmp[i] = MAP[i].clone();
			}
			for (int i = 0; i < S_len; i++) {
				for (int j = 0; j < M; j++) {
					tmp[Selected1[i]][j] = Selected2[i];
				}
			}
			if (check(tmp)) {

				Min = Math.min(Min, S_len);
			}
			return;
		}
		Selected2[cnt] = 1;
		subset2(cnt + 1);
		Selected2[cnt] = 0;
		subset2(cnt + 1);
	}

	private static boolean check(int[][] s) {
		int cnt;
		boolean flag;
		for (int j = 0; j < M; j++) {
			cnt = 1;
			flag = false;
			for (int i = 1; i < N; i++) {
				if (s[i][j] == s[i - 1][j])
					cnt++;
				else
					cnt = 1;
				if (cnt == K)
					flag = true;
			}
			if (!flag)
				return false;
		}
		return true;
	}
}