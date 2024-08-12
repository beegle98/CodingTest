import java.io.*;
import java.util.*;

public class Main {

	final static int N = 4000000;
	static boolean[] primeCheck = new boolean[N+1]; // false = 소수
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		if(n==1) System.out.println("0");
		else {
			for(int i=2;i*i<=N;i++) {
				if(primeCheck[i]) continue;
				for(int j=i*i;j<=N;j+=i) {
					primeCheck[j]=true;
				}
			}
			List<Integer> prime = new ArrayList<>(100000);
			for(int i=2;i<=N;i++) {
				if(!primeCheck[i]) prime.add(i);
			}
			//System.out.println(prime.size());
			int len = prime.size();
			int ans = 0;
			for(int i=0;i<len;i++) {
				int sum = prime.get(i);
				if(sum==n) ans++;
				for(int j=i+1;j<len;j++) {
					sum += prime.get(j);
					if(sum > n) break;
					if(sum==n) ans++;
				}
			}
			System.out.println(ans);
		}
	}

}
