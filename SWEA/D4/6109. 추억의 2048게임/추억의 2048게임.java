import java.io.*;
import java.util.*;
 
public class Solution {
    static int N;
    static String Str;
    static int[][] MAP;
    static int[] dx={-1,1,0,0}; // up,down,right,left
    static int[] dy={0,0,1,-1};
    static boolean[][] flag;
    
    public static void main(String[] args) throws IOException {
         
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
         
        int T = Integer.parseInt(st.nextToken());
         
        for(int tc=1;tc<=T;tc++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            Str = st.nextToken();
            MAP = new int[N][N];
            flag = new boolean[N][N];
            for(int i=0;i<N;i++) {
            	st = new StringTokenizer(br.readLine());
            	for(int j=0;j<N;j++) MAP[i][j]=Integer.parseInt(st.nextToken());
            }
            System.out.println("#"+tc);
            
            if(Str.equals("up")==true) SolveUp();
            else if(Str.equals("down")==true) SolveDown();
            else if(Str.equals("right")==true) SolveRight();
            else if(Str.equals("left")==true) SolveLeft();
            for(int i=0;i<N;i++) {
    			for(int j=0;j<N;j++) {
    				System.out.printf("%d ",MAP[i][j]);
    			}
    			System.out.println();
    		}
        }
      
    }
    private static void SolveUp(){

		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				int x=j;
				int y=i;
				while(x>0) {
					if(flag[x-1][y]==true) break;
					if (MAP[x - 1][y] == 0) {
						MAP[x - 1][y] = MAP[x][y];
						MAP[x][y] = 0;
						x--;
					} else if (MAP[x - 1][y] == MAP[x][y]) {
						MAP[x - 1][y] = 2 * MAP[x - 1][y];
						flag[x-1][y]=true;
						MAP[x][y] = 0;
						break;
					} else {
						break;
					}
				}
			}
		}
    }

	private static void SolveDown() {
		for (int i = 0; i < N; i++) {
			for (int j = N-2; j >= 0; j--) {
				int x=j;
				int y=i;
				while(x<N-1) {
					if(flag[x+1][y]==true) break;
					if (MAP[x+1][y] == 0) {
						MAP[x+1][y] = MAP[x][y];
						MAP[x][y] = 0;
						x++;
					} else if (MAP[x+1][y] == MAP[x][y]) {
						MAP[x+1][y] = 2 * MAP[x+1][y];
						flag[x+1][y]=true;
						MAP[x][y] = 0;
						break;
					} else {
						break;
					}
				}
			}
		}
	}

	private static void SolveRight() {
		for (int i = 0; i < N; i++) {
			for (int j = N-2; j >= 0; j--) {
				int x=i;
				int y=j;
				while(y<N-1) {
					if(flag[x][y+1]==true) break;
					if (MAP[x][y+1] == 0) {
						MAP[x][y+1] = MAP[x][y];
						MAP[x][y] = 0;
						y++;
					} else if (MAP[x][y+1] == MAP[x][y]) {
						MAP[x][y+1] = 2 * MAP[x][y+1];
						flag[x][y+1]=true;
						MAP[x][y] = 0;
						break;
					} else {
						break;
					}
				}
			}
		}
	}
	private static void SolveLeft(){
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				int x=i;
				int y=j;
				while(y>0) {
					if(flag[x][y-1]==true) break;
					if (MAP[x][y-1] == 0) {
						MAP[x][y-1] = MAP[x][y];
						MAP[x][y] = 0;
						y--;
					} else if (MAP[x][y-1] == MAP[x][y]) {
						MAP[x][y-1] = 2 * MAP[x][y-1];
						flag[x][y-1]=true;
						MAP[x][y] = 0;
						break;
					} else {
						break;
					}
				}
			}
		}

	}
    
}