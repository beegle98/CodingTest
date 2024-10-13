import java.io.*;
import java.util.*;

public class Solution {
    static class Pos{
        int x,y;
        int range;

        public Pos(int x, int y, int range) {
            this.x = x;
            this.y = y;
            this.range = range;
        }
    }
    static int N,W,H;
    static int ans;
    static int[][] map,copy;
    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        for(int tc=1;tc<=T;tc++){
            st = new StringTokenizer(br.readLine()," ");

            N = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());

            map = new int[H][W];
            copy = new int[H][W];

            ans = Integer.MAX_VALUE;

            for(int i=0;i<H;i++){
                st = new StringTokenizer(br.readLine()," ");
                for(int j=0;j<W;j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                    copy[i][j] = map[i][j];
                }
            }
            dfs(0,new int[N]);
            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.println(sb);
    }

    static void dfs(int depth,int[] selected){
        if(depth == N){
            if(ans == 0) return;
            
            for(int j : selected){
                for(int i=0;i<H;i++){
                    if(map[i][j] == 0) continue;
                    boom(new Pos(i,j,map[i][j]));
                    break;
                }
                if(count() == 0) {
                    ans = 0;
                    return;
                }
                down();
            }
            ans = Math.min(ans,count());
            copyMap();
            return;
        }
        for(int i=0;i<W;i++){
            selected[depth] = i;
            dfs(depth+1,selected);
        }
    }
    static void boom(Pos start){
        Queue<Pos> que = new ArrayDeque<>();
        que.add(start);
        map[start.x][start.y] = 0;

        while(!que.isEmpty()){
            Pos curr = que.poll();
            int range = curr.range;
            for(int r=1;r<range;r++){
                
                for(int i=0;i<4;i++){
                    int nx = curr.x + dx[i] * r;
                    int ny = curr.y + dy[i] * r;

                    if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                    if(map[nx][ny] == 0) continue;

                    que.add(new Pos(nx,ny,map[nx][ny]));
                    map[nx][ny] = 0; 
                }
            }
        }
    }
    static int count(){
        int cnt = 0;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(map[i][j] > 0) cnt++;
            }
        }
        return cnt;
    }

    static void down(){
        for(int j=0;j<W;j++){
            Stack<Integer> stack = new Stack<>();
            for(int i=0;i<H;i++){
                if(map[i][j] == 0) continue;
                stack.add(map[i][j]);
            }
            for(int i=H-1;i>=0;i--){
                if(stack.isEmpty()) {
                    map[i][j] = 0;
                    continue;
                }
                map[i][j] = stack.pop();
            }
        }
    }
    static void copyMap(){
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                map[i][j] = copy[i][j];
            }
        }
    }
}