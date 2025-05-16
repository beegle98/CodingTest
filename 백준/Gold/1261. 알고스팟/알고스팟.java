import java.io.*;
import java.util.*;

public class Main {

    static class Node{
        int x;
        int y;
        int dist;
        Node(int x, int y, int dist){
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
    static int n,m;
    static int[][] arr;
    static int[][] dist;
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,1,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        dist = new int[n][m];
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = s.charAt(j) - '0';
                dist[i][j] = Integer.MAX_VALUE;
            }
        }
        solve(0,0);
        System.out.println(dist[n-1][m-1]);
    }
    private static void solve(int x, int y) {
        PriorityQueue<Node> pq = new PriorityQueue<>((o1,o2)->{
            return o1.dist-o2.dist;
        });
        dist[x][y] = 0;
        pq.offer(new Node(x,y,0));
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            if(cur.x==n-1 && cur.y==m-1) return;
            if(dist[cur.x][cur.y]<cur.dist) continue;
            for(int i=0;i<4;i++){
                int nx = cur.x+dx[i];
                int ny = cur.y+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if(cur.dist + arr[nx][ny]<dist[nx][ny]){
                    pq.offer(new Node(nx,ny,cur.dist+arr[nx][ny]));
                    dist[nx][ny] = cur.dist+arr[nx][ny];
                }
            }
        }
    }
}
