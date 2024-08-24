
import java.util.*;
import java.io.*;

public class Solution {
		static int N,M,len;
		static char[][] MAP;
		static String str;
		static int[] dx = {-1,0,1,0};
		static int[] dy = {0,1,0,-1};
		static HashMap<Character, Integer> tank = new HashMap<>(); 
	
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	int t = Integer.parseInt(st.nextToken());
    	tank.put('^', 0);
    	tank.put('>', 1);
    	tank.put('v', 2);
    	tank.put('<', 3);
    	for(int tc=1;tc<=t;tc++) {
    		st = new StringTokenizer(br.readLine());
    		N = Integer.parseInt(st.nextToken());
    		M = Integer.parseInt(st.nextToken());
    		MAP = new char[N][M];
    		
    		for(int i=0;i<N;i++) {
    			MAP[i] = br.readLine().toCharArray();
    		}
    		len = Integer.parseInt(br.readLine());
    		str = br.readLine();
    		solve();
    		System.out.print("#"+tc+" ");
    		print();
    	}
    }
    private static void solve() {
    	int x=0,y=0,d=0;
    	loop:
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<M;j++) {
    			d=tank.getOrDefault(MAP[i][j],-1);
    			if(d!=-1) {
    				x=i;
    				y=j;
    				break loop;
    			}
    		}
    	}
    	int idx=0;
    	while(idx<len) {
    		//System.out.println(idx+ " : " +x + " " + y + " " + d);
    		if(str.charAt(idx)=='S') {
    			
    			dfs(x,y,d);
    		}else if(str.charAt(idx)=='U') {
    			d=0;
    			if(check(x,y,d)) {
    				MAP[x][y]='.';
    				x+=dx[d];
    				y+=dy[d];
    			}
    			MAP[x][y]='^';
    		}else if(str.charAt(idx)=='R') {
    			d=1;
    			if(check(x,y,d)) {
    				MAP[x][y]='.';
    				x+=dx[d];
    				y+=dy[d];
    			}
    			MAP[x][y]='>';
    		}else if(str.charAt(idx)=='D') {
    			d=2;
    			if(check(x,y,d)) {
    				MAP[x][y]='.';
    				x+=dx[d];
    				y+=dy[d];
    			}
    			MAP[x][y]='v';
    		}else if(str.charAt(idx)=='L') {
    			d=3;
    			if(check(x,y,d)) {
    				MAP[x][y]='.';
    				x+=dx[d];
    				y+=dy[d];
    			}
    			MAP[x][y]='<';
    		}
    		idx++;
    	}
    }
	private static boolean check(int x, int y, int d) {
		int nx = x+dx[d];
		int ny = y+dy[d];
		if(nx<0 || nx >= N || ny<0 || ny>=M || MAP[nx][ny]!='.') return false;
		return true;
	}
	private static void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				System.out.print(MAP[i][j]);
			}
			System.out.println();
		}
	}
    private static void dfs(int x,int y,int d) {
    	if(x<0||x>=N||y<0||y>=M||MAP[x][y]=='#') return;
    	if(MAP[x][y]=='*') {
    		MAP[x][y]='.';
    		return;
    	}
    	dfs(x+dx[d],y+dy[d],d);
    }
}

