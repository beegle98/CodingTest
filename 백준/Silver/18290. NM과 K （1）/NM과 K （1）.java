import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {

    static int n,m,k, ans=-10000000;
    static int[][] s = new int[20][20];
    static boolean[][] visited = new boolean[20][20];
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=m;j++){
                s[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        solve(1,1,0, 0);
        System.out.println(ans);
    }
    static void solve(int x,int y,int cnt, int sum){
        if(cnt==k) {
            ans = Math.max(ans, sum);
            return;
        }
        for(int i=x;i<=n;i++){
            for(int j = (i==x ? y : 1);j<=m;j++){
                if(!visited[i][j] && !adj(i,j)){
                    visited[i][j] = true;
                    if(j==m) solve(i+1,1,cnt+1,sum+s[i][j]);
                    else solve(i,j+1,cnt+1,sum+s[i][j]);
                    visited[i][j] = false;
                }
            }
        }
    }
    static boolean adj(int x,int y){
        for(int i=0;i<4;i++){
            if(visited[x+dx[i]][y+dy[i]]) return true;
        }
        return false;
    }
}