import java.util.*;
import java.io.*;

public class Solution {
	static int[] parent;
	static int N,M;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
		for(int tc=1;tc<=T;tc++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#" + tc + " ");
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			// makeSet
			parent = MakeSet(N+1);
			for(int i=0;i<M;i++) {
				st = new StringTokenizer(br.readLine());
				int k,a,b;
				k = Integer.parseInt(st.nextToken());
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				if(k==0) {
					union(a,b);
				}else if(k==1) {
					if(find(a)==find(b)) sb.append("1");
					else sb.append("0");
				}
			}
			System.out.println(sb.toString());
		}

		
	}
	
	// Union
	private static void union(int a, int b) {
		a = find(a);
		b = find(b);
		if (a > b) parent[a] = b;
		else parent[b] = a;
	}

	// Find
	private static int find(int x) {
		if (parent[x] == x) return x;
		else return parent[x] = find(parent[x]);
	}

	// makeSet
	private static int[] MakeSet(int size) {
		int[] arr = new int[size];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = i;
		}
		return arr;
	}
}
