import java.util.*;
import java.io.*;

public class Main {
	static int[] parent;
	static int N,M;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		// makeSet
		parent = MakeSet(N+1);
		
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1;j<=N;j++) {
				int k = Integer.parseInt(st.nextToken());
				if(k==1) union(i,j);
			}
		}
		int[] arr = new int[M];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<M;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		if(Check(arr)) System.out.println("YES");
		else System.out.println("NO");
		
	}
	private static boolean Check(int[] arr) {
		int p = find(arr[0]);
		for(int i=1;i<arr.length;i++) {
			if(p != find(arr[i])) return false;
		}
		return true;
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
