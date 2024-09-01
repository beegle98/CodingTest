import java.io.*;
import java.util.*;
  
public class Main {
    static int N, ans;
    static int K = 5;
    static int[] dx={-1,1,0,0}; // up,down,right,left
    static int[] dy={0,0,1,-1};
     
    public static void main(String[] args) throws IOException {
          
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
          
        N = Integer.parseInt(st.nextToken());
          
		int[][] map = new int[N][N];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++)
				map[i][j] = Integer.parseInt(st.nextToken());
		}
		ans = 0;
		recur(0,map);
		System.out.println(ans);
    }
    private static void calMax(int[][] map) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				ans = Math.max(ans, map[i][j]);
			}
		}
    }
    private static void recur(int depth, int[][] map) {
    	if(depth==K) {
    		calMax(map);
    		return;
    	}
    	recur(depth+1,MoveUp(map));
    	recur(depth+1,MoveDown(map));
    	recur(depth+1,MoveLeft(map));
    	recur(depth+1,MoveRight(map));
    }
    private static int[][] MoveUp(int[][] map){
    	boolean[][] flag = new boolean[N][N];
    	int[][] tmp = new int[N][N];
    	for(int i=0;i<N;i++) tmp[i] = map[i].clone();
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < N; j++) {
                int x=j;
                int y=i;
                while(x>0) {
                    if(flag[x-1][y]==true) break;
                    if (tmp[x - 1][y] == 0) {
                        tmp[x - 1][y] = tmp[x][y];
                        tmp[x][y] = 0;
                        x--;
                    } else if (tmp[x - 1][y] == tmp[x][y]) {
                        tmp[x - 1][y] = 2 * tmp[x - 1][y];
                        flag[x-1][y]=true;
                        tmp[x][y] = 0;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        return tmp;
    }
 
    private static int[][] MoveDown(int[][] map) {
    	boolean[][] flag = new boolean[N][N];
    	int[][] tmp = new int[N][N];
    	for(int i=0;i<N;i++) tmp[i] = map[i].clone();
        for (int i = 0; i < N; i++) {
            for (int j = N-2; j >= 0; j--) {
                int x=j;
                int y=i;
                while(x<N-1) {
                    if(flag[x+1][y]==true) break;
                    if (tmp[x+1][y] == 0) {
                        tmp[x+1][y] = tmp[x][y];
                        tmp[x][y] = 0;
                        x++;
                    } else if (tmp[x+1][y] == tmp[x][y]) {
                        tmp[x+1][y] = 2 * tmp[x+1][y];
                        flag[x+1][y]=true;
                        tmp[x][y] = 0;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        return tmp;
    }
 
    private static int[][] MoveRight(int[][] map) {
    	boolean[][] flag = new boolean[N][N];
    	int[][] tmp = new int[N][N];
    	for(int i=0;i<N;i++) tmp[i] = map[i].clone();
        for (int i = 0; i < N; i++) {
            for (int j = N-2; j >= 0; j--) {
                int x=i;
                int y=j;
                while(y<N-1) {
                    if(flag[x][y+1]==true) break;
                    if (tmp[x][y+1] == 0) {
                        tmp[x][y+1] = tmp[x][y];
                        tmp[x][y] = 0;
                        y++;
                    } else if (tmp[x][y+1] == tmp[x][y]) {
                        tmp[x][y+1] = 2 * tmp[x][y+1];
                        flag[x][y+1]=true;
                        tmp[x][y] = 0;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        return tmp;
    }
    private static int[][] MoveLeft(int[][] map){
    	boolean[][] flag = new boolean[N][N];
    	int[][] tmp = new int[N][N];
    	for(int i=0;i<N;i++) tmp[i] = map[i].clone();
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < N; j++) {
                int x=i;
                int y=j;
                while(y>0) {
                    if(flag[x][y-1]==true) break;
                    if (tmp[x][y-1] == 0) {
                        tmp[x][y-1] = tmp[x][y];
                        tmp[x][y] = 0;
                        y--;
                    } else if (tmp[x][y-1] == tmp[x][y]) {
                        tmp[x][y-1] = 2 * tmp[x][y-1];
                        flag[x][y-1]=true;
                        tmp[x][y] = 0;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        return tmp;
    }
     
}