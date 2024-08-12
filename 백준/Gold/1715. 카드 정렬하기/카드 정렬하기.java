import java.io.*;
import java.util.*;


public class Main {
	
	static PriorityQueue<Integer> pq = new PriorityQueue<>();
	
	
	public static void main(String[] args) throws IOException{
		
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		for(int i=0;i<n;i++) {
			int x = sc.nextInt();
			pq.add(x);
		}
		int sum=0;
		for(int i=0;i<n-1;i++) {
			int a = pq.poll();
			int b = pq.poll();
			sum += a+b;
			pq.add(a+b);
		}
		System.out.println(sum);
	}

}
