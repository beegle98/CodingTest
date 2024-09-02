import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N,L,D;
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		int time=0;
		while(time<N*(L+5)) {
			time+=D;
			if(time%(L+5) >= L) break;
		}
		System.out.println(time);
	}

}