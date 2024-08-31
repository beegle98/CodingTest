import java.util.*;
import java.io.*;

public class Main {
	static class Node{
		double x,y;
		public Node(double x, double y) {
			super();
			this.x = x;
			this.y = y;
		}
	}
	static int N;
	static Node[] list;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		list = new Node[N];
		double[][] map = new double[N][N];
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			double a,b;
			a = Double.parseDouble(st.nextToken());
			b = Double.parseDouble(st.nextToken());
			list[i] = new Node(a,b);
		}
		for(int i=0;i<N;i++) {
			map[i][i]=0;
			for(int j=i;j<N;j++) {
				map[i][j] = map[j][i] = len(i,j);
			}
		}
		// prim 시작
		boolean[] visited = new boolean[N];
		double[] Dist = new double[N];
		Arrays.fill(Dist, Double.MAX_VALUE);
		Dist[0] = 0.0;
		
		double min,sum=0;
		int minVertex;
		
		for(int i=0;i<N;i++) {
			min = Double.MAX_VALUE;
			minVertex=-1;
			
			for(int j=0;j<N;j++) {
				if(!visited[j] && Dist[j] < min) {
					min = Dist[j];
					minVertex=j;
				}
			}
			if(minVertex==-1) break;
			sum += min;
			visited[minVertex] = true;
			
			for(int j=0;j<N;j++) {
				if( !visited[j] && map[minVertex][j] < Dist[j] ) {
					Dist[j] = map[minVertex][j];
				}
			}
		}
		
		System.out.println(String.format("%.2f", sum));
	}
	private static double len(int a,int b) {
		return Math.sqrt(Math.pow(list[a].x-list[b].x, 2) + Math.pow(list[a].y-list[b].y, 2));
	}
}
