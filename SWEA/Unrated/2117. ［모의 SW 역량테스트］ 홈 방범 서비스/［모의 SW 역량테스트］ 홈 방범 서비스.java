import java.io.*;
import java.util.*;

public class Solution {

    static int N,M,ans;
    static int[][] map;

    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(st.nextToken());
        
        for (int tc = 1; tc <= T; tc++) {
        	st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            map = new int[N][N];
            for(int i=0;i<N;i++) {
            	st = new StringTokenizer(br.readLine());
            	for(int j=0;j<N;j++) {
            		map[i][j] = Integer.parseInt(st.nextToken());
            	}
            }
            ans=0;
            for(int k=N+1;k>0;k--) {
            	for(int i=0;i<N;i++) {
            		for(int j=0;j<N;j++) {
            			int ret = HomeCount(i,j,k);
            			ans = Math.max(ans, ret);
            		}
            	}
            }
            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.print(sb.toString());
    }


	private static int HomeCount(int x, int y, int k) {
		int c=0, cnt=0;
		for(int i=x-k+1;i<=x;i++) {
			for(int j=y-c;j<=y+c;j++) {
				if(i<0 || i>=N || j<0 || j>=N) continue;
				if(map[i][j]==1) cnt++;
			}
			c++;
		}
		c=0;
		for(int i=x+k-1;i>x;i--) {
			for(int j=y-c;j<=y+c;j++) {
				if(i<0 || i>=N || j<0 || j>=N) continue;
				if(map[i][j]==1) cnt++;
			}
			c++;
		}
		if(k*k+(k-1)*(k-1) <= cnt*M) return cnt;
		else return 0;
	}
}