import java.io.*;
import java.util.*;
 
public class Solution {
 
    static int N,X,ans;
    static int[][] map;
    static boolean[][] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(st.nextToken());
         
        for (int tc = 1; tc <= T; tc++) {
        	st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            X = Integer.parseInt(st.nextToken());
            map = new int[N][N];
            
            
            for(int i=0;i<N;i++) {
            	st = new StringTokenizer(br.readLine());
                for(int j=0;j<N;j++) {
                	map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            ans=0;
            int prev, next, cur;
            // 가로 체크
            visited = new boolean[N][N];
            for(int i=0;i<N;i++) {
            	boolean flag=true;
            	for(int j=0;j<N-1;j++) {
            		if(!flag) break;
            		if(map[i][j]<map[i][j+1] && !leftCheck(i,j+1)) flag=false;
            		if(map[i][j]>map[i][j+1] && !rightCheck(i,j)) flag=false;
            	}
            	if(flag) ans++;
            	
            }
            // 세로 체크
            visited = new boolean[N][N];
            for(int i=0;i<N;i++) {
            	boolean flag=true;
            	for(int j=0;j<N-1;j++) {
            		if(!flag) break;
            		if(map[j][i]<map[j+1][i] && !upCheck(j+1,i)) flag=false;
            		if(map[j][i]>map[j+1][i] && !downCheck(j,i)) flag=false;
            	}
            	if(flag) ans++;
            	
            }
            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.print(sb.toString());
    }
	private static boolean upCheck(int i, int j) {
		if(i<X || map[i][j]-1!=map[i-1][j]) return false;
		visited[i-1][j]=true;
		for(int k=1;k<X;k++) {
			if(visited[i-k-1][j] || map[i-k][j]!=map[i-k-1][j]) return false;
			visited[i-k-1][j]=true;
		}
		return true;
	}
	private static boolean downCheck(int i, int j) {
		if(i>=N-X || map[i][j]-1!=map[i+1][j]) return false;
		
		visited[i+1][j]=true;
		for(int k=1;k<X;k++) {
			if(visited[i+k+1][j] || map[i+k][j]!=map[i+k+1][j]) return false;
			visited[i+k+1][j]=true;
		}
		return true;
	}
	private static boolean leftCheck(int i, int j) {
		if(j<X || map[i][j]-1!=map[i][j-1]) return false;
		visited[i][j-1]=true;
		for(int k=1;k<X;k++) {
			if(visited[i][j-k-1] || map[i][j-k]!=map[i][j-k-1]) return false;
			visited[i][j-k-1]=true;
		}
		return true;
	}
	private static boolean rightCheck(int i, int j) {
		if(j>=N-X || map[i][j]-1!=map[i][j+1]) return false;
		visited[i][j+1]=true;
		for(int k=1;k<X;k++) {
			if(visited[i][j+k+1] || map[i][j+k]!=map[i][j+k+1]) return false;
			visited[i][j+k+1]=true;
		}
		return true;
	}
     
}
