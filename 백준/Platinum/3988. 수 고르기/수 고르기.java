import java.io.*;
import java.util.*;

public class Main {
    static class Data {
    	int value;
    	int idx;
		public Data(int value, int idx) {
			super();
			this.value = value;
			this.idx = idx;
		}
    	
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N,K;
        int Max,Min,ans;
        Max = 0;
        Min = ans = Integer.MAX_VALUE;
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        K = N - K;
        Deque<Data> dq = new LinkedList<>();
        for(int i=1;i<N;i++) {
        	int diff = arr[i]-arr[i-1];
        	while(!dq.isEmpty() && dq.peekLast().value >= diff) dq.pollLast();
        	dq.offerLast(new Data(diff,i));
        	while(dq.peekFirst().idx <= i-K+1) dq.pollFirst();
        	if(i>= K-1) ans = Math.min(ans, arr[i]-arr[i-K+1]+dq.peekFirst().value);
        }
        System.out.println(ans);
    }
    
}