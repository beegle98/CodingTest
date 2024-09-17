import java.io.*;
import java.util.*;

public class Main {

    static long N,P,Q;
    static Map<Long, Long> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Long.parseLong(st.nextToken());
        P = Long.parseLong(st.nextToken());
        Q = Long.parseLong(st.nextToken());
        long ans = recur(N);
        System.out.println(ans);
    }
    static long recur(long n) {
    	if(n==0) return 1;
    	if(map.containsKey(n)) return map.get(n);
    	long res = recur(n/P) + recur(n/Q);
    	map.put(n,res);
    	return res;
    }
}