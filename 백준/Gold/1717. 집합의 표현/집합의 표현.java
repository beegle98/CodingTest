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
		// makeSet
		parent = new int[N];
		parent = MakeSet(N);
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int k,a,b;
			k = Integer.parseInt(st.nextToken());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			if(k==0) {
				union(a,b);
			}else if(k==1) {
				if(find(a)==find(b)) {
					System.out.println("YES");
				}else System.out.println("NO");
			}
		}
		
		
	}

	// Union
	private static void union(int a, int b) {
		// 각 집합을 대표하는 부모가 다른 부모로 편입 되어야 한다. 원소가 편입되어서는 안된다.
		a = find(a);
		b = find(b);
		// 일반적으로 더 작은 값으로 다른 집합이 편입되도록 한다.
		if (a > b) {
			parent[a] = b;
		} else {
			parent[b] = a;
		}
	}

	// Find
	private static int find(int x) {
		// 만일, 찾는 대상과 인덱스 번호가 같다면 그 인덱스(=노드)가 해당 집합의 부모이다.
		if (parent[x] == x)
			return x;
		// 경로 압축
		else
			return parent[x] = find(parent[x]);
	}

	// makeSet
	private static int[] MakeSet(int size) {
		// 각 인덱스에 번호가 대응하도록 사이즈를 1더하여 배열 선언.
		int[] arr = new int[size + 1];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = i;
		}
		return arr;
	}
}
