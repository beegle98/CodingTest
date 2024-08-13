import java.io.*;
import java.util.*;

public class Solution {
	static int win=0,lose=0;
	static int N = 9;
	static int[] a = new int[N];
	static int[] b = new int[N];
	public static void check() {
		int sum=0;
		for(int i=0;i<N;i++) {
			if(a[i]>b[i]) sum += a[i]+b[i];
			else sum -= a[i]+b[i];
		}
		if(sum>0) win++;
		else if(sum<0) lose++;
	}
	public static void swap(int t1,int t2) {
		int tmp = b[t1];
		b[t1] = b[t2];
		b[t2]=tmp;
	}
	public static void permutation(int depth) {
		
		if(depth == N-1) {
			check();
			return;
		}
		
		for (int i = depth; i <N; i++) {
			swap(i,depth);
			permutation(depth+1);
			swap(depth,i);
		}
	}
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc=1;tc<=T;tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			boolean[] selected= new boolean[(N+1)*2];
			win=0;
			lose=0;
			for(int i=0;i<N;i++) {
				a[i] = Integer.parseInt(st.nextToken());
				selected[a[i]]=true;
			}
			int cnt=0;
			for(int i=1;i<=N*2;i++) {
				if(!selected[i]) b[cnt++]= i;
				selected[i]=false;//초기화
			}
			permutation(0);
			System.out.println("#" + tc + " " + win + " " + lose);
			
		}
	}

}
