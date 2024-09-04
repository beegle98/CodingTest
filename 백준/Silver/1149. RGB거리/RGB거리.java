import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int[] cur = new int[3];
        int[] next = new int[3];
        
    	for (int i = 0; i < N; i++){
    		st = new StringTokenizer(br.readLine());
    		for (int j=0;j<3;j++) {
    			next[j] = Integer.parseInt(st.nextToken());
    			next[j] += Math.min(cur[(j+1)%3], cur[(j+2)%3]);
    		}
    		for (int j = 0; j < 3; j++) cur[j] = next[j];
    	}
    	int min=Integer.MAX_VALUE;
    	for(int i=0;i<3;i++) min = Math.min(min,cur[i]);
    	System.out.println(min);
    }
    
}