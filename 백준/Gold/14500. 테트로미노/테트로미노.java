import java.io.*;
import java.util.*;

public class Main {

    static int ans = 0;
    static int n,m;
    static int[][] map;
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    static boolean[][] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        visited = new boolean[n][m];
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                visited[i][j] = true;
                dfs(i,j,0,map[i][j]);
                visited[i][j] = false;
            }
        }
        System.out.println(ans);
    }
    static void dfs(int x,int y, int depth, int sum){
        if(depth==3){
            ans = Math.max(ans,sum);
            return;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny]) continue;
            if(depth==1){ // ㅏ,ㅜ,ㅓ,ㅗ 형태
                visited[nx][ny] = true;
                dfs(x,y,depth+1,sum+map[nx][ny]);
                visited[nx][ny] = false;
            }
            visited[nx][ny] = true;
            dfs(nx,ny,depth+1,sum+map[nx][ny]);
            visited[nx][ny] = false;
        }
    }
}
