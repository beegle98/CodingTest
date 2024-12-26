import java.io.*;
import java.util.*;

public class Main {
    static final int MIN = -1000000000;
    static int N,M;
    static int[][][] dp;
    static int[][] s;
    static boolean[][] visited;
    static int[] dx = {1,0,0};
    static int[] dy = {0,1,-1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        dp = new int[N][M][3];// 위, 좌, 우
        visited = new boolean[N][M];
        s = new int[N][M];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++){
                s[i][j]=Integer.parseInt(st.nextToken());
                Arrays.fill(dp[i][j], MIN);
            }
        }

        visited[0][0]=true;
        int ans = dfs(0,0,0);
        System.out.println(ans);
    }
    static int dfs(int x, int y, int dir){

        if(x==N-1 && y==M-1) return s[x][y];
        if(dp[x][y][dir] != MIN) return dp[x][y][dir];

        visited[x][y] = true;
        int res=MIN;
        for(int i=0;i<3;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M || visited[nx][ny]) continue;
            res = Math.max(res,dfs(nx,ny,i));
        }
        visited[x][y] = false;
        dp[x][y][dir] = s[x][y] + res;
        return dp[x][y][dir];
    }
}
