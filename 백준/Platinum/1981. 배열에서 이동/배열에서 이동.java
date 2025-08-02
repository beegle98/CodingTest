import java.util.*;
import java.io.*;

public class Main {
    static class Pos{
        int x, y;
        public Pos(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    static int N;
    static int[] dx = {0,1,0,-1};
    static int[] dy = {1,0,-1,0};
    static int[][] map;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        map = new int[N][N];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                map[i][j] = Integer.parseInt(st.nextToken());

            }
        }
        int l = 0, r = 200;
        int ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            boolean key = false;
            for(int i = 0; i <= 200-mid; i++) {
                int s = i;
                int e = i + mid;
                if(bfs(s,e)){
                    key = true;
                    break;
                }
            }
            if (key) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        System.out.println(ans);
    }
    static boolean bfs(int s,int e){
        if(map[0][0] < s || map[0][0] > e) return false;
        Queue<Pos> q = new LinkedList<>();
        boolean[][] visited = new boolean[N][N];
        q.add(new Pos(0,0));
        visited[0][0] = true;
        while(!q.isEmpty()){
            Pos cur = q.poll();
            if(cur.x==N-1 && cur.y==N-1) return true;
            for(int i = 0; i < 4; i++){
                int nx = cur.x+dx[i];
                int ny = cur.y+dy[i];
                if(nx<0||ny<0||nx>=N||ny>=N||visited[nx][ny] || map[nx][ny]<s || map[nx][ny]>e) continue;
                visited[nx][ny] = true;
                q.add(new Pos(nx, ny));
            }
        }
        return false;
    }
}