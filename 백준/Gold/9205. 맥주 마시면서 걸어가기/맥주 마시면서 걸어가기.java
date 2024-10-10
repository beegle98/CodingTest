

import java.io.*;
import java.util.*;

public class Main {

	private final static int INF = (int)1e9; 
    private static int[][] dp;
    private static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        for(int tc=1;tc<=T;tc++) {
            N = Integer.parseInt(br.readLine());
            N+=2;
            dp = new int[N][N];
            

            int[][] Pos = new int[N][2];
            for(int i=0;i<N;i++) {
            	st = new StringTokenizer(br.readLine());
            	int x = Integer.parseInt(st.nextToken()); 
            	int y = Integer.parseInt(st.nextToken());
            	Pos[i][0]=x;
            	Pos[i][1]=y;
            }
            for(int i=0;i<N;i++) {
            	for(int j=0;j<N;j++) {
            		if(Math.abs(Pos[i][0]-Pos[j][0])+Math.abs(Pos[i][1]-Pos[j][1])<=1000) dp[i][j]=1;
            		else dp[i][j]=INF;
            	}
            }
        	for(int k=0;k<N;k++) {
        		for(int i=0;i<N;i++) {
        			for(int j=0;j<N;j++) {
        				dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
        			}
        		}
        	}
        	if(dp[0][N-1]==INF) System.out.println("sad");
        	else System.out.println("happy");

        }

    }
}
