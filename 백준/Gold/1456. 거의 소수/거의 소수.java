import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
public class Main {
	
	final static int N = 10000000;
	static boolean[] primeCheck = new boolean[N+1]; // false = PrimeNumber
	public static void main(String[] args) throws IOException{
		
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner sc = new Scanner(System.in);
		
		for(int i=2;i*i<=N;i++) {
			if(!primeCheck[i]) {
				for(int j=i*i;j<=N;j+=i) {
					primeCheck[j]=true;
				}
			}
		}
		ArrayList<Integer> pr = new ArrayList<>(100000);
		Set<Long> ans = new HashSet<>();
		
		for(int i=2;i<=N;i++) {
			if(!primeCheck[i]) pr.add(i);
		}
		long a,b;
		a = sc.nextLong();
		b = sc.nextLong();
		
		int n=2;
		while((long)Math.pow(2, n)<=b) {
			for(int i=0;i<pr.size();i++) {
				long p = (long)Math.pow(pr.get(i), n);
				if(p>b) break;
				if(p>=a) ans.add(p);
			}
			n++;
		}
	
		
		System.out.println(ans.size());
	}

}
