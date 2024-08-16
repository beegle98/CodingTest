import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;



public class Main {
	
	
	static int N,ans;
	static int[][] cook= new int[2][11];

	public static void main(String[] args) throws IOException{
		
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		for(int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			cook[0][i]= Integer.parseInt(st.nextToken());
			cook[1][i]= Integer.parseInt(st.nextToken());
			
		}
		ans=Integer.MAX_VALUE;
		recur(0,1,0,0);
		
		System.out.println(ans);
	}
	public static void recur(int idx, int S, int B,int checked) {
		if(idx==N) {
			if(checked==0) return;
			int dif = Math.abs(S-B);
			if(ans > dif) ans = dif;
			return;
		}
		recur(idx+1, S*cook[0][idx], B+cook[1][idx], checked | 1<<idx);
		recur(idx+1, S, B, checked);
	}
}

