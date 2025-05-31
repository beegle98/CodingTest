import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    static class Node implements Comparable<Node> {
        int x;
        int y;
        int gb;
        int adj;

        public Node(int x, int y, int gb, int adj) {
            this.x = x;
            this.y = y;
            this.gb = gb;
            this.adj = adj;
        }

        @Override
        public int compareTo(Node o) {
            if(this.gb==o.gb) return this.adj-o.adj;
            return this.gb-o.gb;
        }
    }

    static int n,m;
    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};
    static Node[][] dp;
    static char[][] map;
    static int endX,endY;
    static int MAX = 10000;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new char[n][m];
        dp = new Node[n][m];
        int sx=0,sy=0;
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                dp[i][j] = new Node(i,j,MAX,MAX);
                map[i][j] = s.charAt(j);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(map[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }else if(map[i][j] == 'F') {
                    endX = i;
                    endY = j;
                }else if(map[i][j] == 'g') {
                    setAdj(i, j);
                }
            }
        }
        dijkstra(new Node(sx,sy,0,0));
        System.out.println(dp[endX][endY].gb + " " + dp[endX][endY].adj);
    }
    static void dijkstra(Node start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(start);
        while(!pq.isEmpty()) {
            Node cur = pq.poll();
            //System.out.println(cur.x + " " + cur.y + " " + cur.gb + " " + cur.adj);
            if (cur.gb > dp[cur.x][cur.y].gb ||
                    (cur.gb == dp[cur.x][cur.y].gb && cur.adj > dp[cur.x][cur.y].adj)) continue;
            if(map[cur.x][cur.y]=='F') break;

            for(int i=0;i<4;i++){
                int nx = cur.x+dx[i],ny = cur.y+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                int ng = cur.gb + (map[nx][ny]=='g' ? 1 : 0);
                int na = cur.adj + (map[nx][ny]=='a' ? 1 : 0);
                if (ng > dp[nx][ny].gb ||
                        (ng == dp[nx][ny].gb && na >= dp[nx][ny].adj)) continue;
                //System.out.println("Add: " + nx + " " + ny + " " + ng + " " + na);
                pq.offer(new Node(nx,ny,ng,na));
                dp[nx][ny].gb = ng;
                dp[nx][ny].adj = na;
            }
        }
    }
    static void setAdj(int x, int y) {
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m || map[nx][ny]!='.') continue;
            map[nx][ny]='a';
        }
    }
}