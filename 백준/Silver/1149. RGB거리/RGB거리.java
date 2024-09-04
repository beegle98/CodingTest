import java.io.*;
import java.util.*;


public class Main{//_1149_S1_RGB거리_이현지 {
	static int N;
	static int[][] table, memo;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		memo = new int[N][3];
		table = new int[N][3];
		StringTokenizer st;
		for(int i=0; i<N; i++) {
			st= new StringTokenizer(br.readLine());
			for(int j=0; j<3; j++) {
				table[i][j] = Integer.parseInt(st.nextToken());
			}
			
		}
		for(int i=0; i<N; i++) {
			if(i != 0) {
				for(int j=0; j<3; j++) {
					memo[i][j] = Math.min(memo[i-1][(j+1)%3], memo[i-1][(j+2)%3])+table[i][j];
				}
			}else {
				for(int j=0; j<3; j++) {
					memo[0][j] = table[0][j];
				}
			}
		}
//		for(int i=0; i<N; i++) {
//			System.out.println(Arrays.toString(memo[i]));
//		}
		System.out.println(Math.min(memo[N-1][0], Math.min(memo[N-1][1], memo[N-1][2])));
	}

}