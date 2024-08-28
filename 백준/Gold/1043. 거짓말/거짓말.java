import java.util.*;
import java.io.*;

public class Main {
	static int[] parent;
	static int N,M;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		ArrayList<Integer>[] party = new ArrayList[M];
		// makeSet
		parent = MakeSet(N+1);
		st = new StringTokenizer(br.readLine());
		int k = Integer.parseInt(st.nextToken());
		for(int i=0;i<k;i++) {
			int a = Integer.parseInt(st.nextToken());
			union(0,a);
		}
		int ans=0;
		for(int i=0;i<M;i++) {
			party[i] = new ArrayList<>();
			st = new StringTokenizer(br.readLine());
			k = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			party[i].add(a);
			int p = find(a);
			for(int j=1;j<k;j++) {
				a = Integer.parseInt(st.nextToken());
				party[i].add(a);
				union(p,a);
			}
		}
		for(int i=0;i<M;i++) {
			int flag=1;
			for(int j=0;j<party[i].size();j++) {
				if(find(0)==find(party[i].get(j))){
					flag=0;
					break;
				}
			}
			ans+=flag;
		}
		System.out.println(ans);
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
