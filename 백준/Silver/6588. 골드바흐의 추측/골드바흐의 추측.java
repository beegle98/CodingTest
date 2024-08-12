import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
public class Main {
	
	final static int N = 1000000;
	static boolean[] pr = new boolean[N+1];
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for(int i=2;i*i<=N;i++) {
			if(!pr[i]) {
				for(int j=i*i;j<=N;j+=i) {
					pr[j]=true;
				}
			}
		}
		
		int n;
		n = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
	
		
		while(n!=0) {
			
			int x=0,y=0;
			
			for(int i=2;i<=n/2;i++) {
				if(!pr[i] && !pr[n-i]) {
					x=i;
					y=n-i;
					break;
				}
			}
			if(x!=0) {
				sb.append(n+" = "+x+" + "+y+"\n");
			}
			else sb.append("Goldbach's conjecture is wrong.");
			
			n = Integer.parseInt(br.readLine());
		}
		System.out.println(sb);
	}

}
