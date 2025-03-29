import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {

    static int[][] map = new int[1002][1002];
    static int n,m, ans=0, cnt=0, t=0;
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    static int[][] group = new int[1002][1002];
    static boolean[][] visited = new boolean[1002][1002];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for(int i=1;i<=n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        HashMap<Integer,Integer> sum = new HashMap<>();
        sum.put(0,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!visited[i][j] && map[i][j]==1){
                    cnt=0;
                    t++;
                    dfs(i,j);
                    sum.put(t,cnt);
                }
            }
        }
        List<Integer> dup = new ArrayList<>();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(map[i][j]==0){
                    int tmp=0;
                    for(int k=0;k<4;k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(map[nx][ny]==1){
                            boolean key=true;
                            for(int a : dup){
                                if(a==group[nx][ny]) key=false;
                            }
                            if(key){
                                dup.add(group[nx][ny]);
                                tmp += sum.get(group[nx][ny]);
                            }
                        }
                    }
                    ans = Math.max(tmp,ans);
                    dup.clear();
                }
            }
        }
        System.out.println(ans+1);
    }
    static void dfs(int x,int y){
        visited[x][y] = true;
        group[x][y] = t;
        cnt++;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!visited[nx][ny] && map[nx][ny]==1) dfs(nx,ny);
        }
    }

}