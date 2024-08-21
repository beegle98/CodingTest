
import java.util.*;
import java.io.*;


public class Main {
		
	static int[] num;
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	int n = Integer.parseInt(br.readLine());
    	num = new int[n];
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	for(int i=0;i<n;i++) {
    		num[i] = Integer.parseInt(st.nextToken());
    	}
    	Arrays.sort(num);
    	
    	int ans=0;
    	for(int i=0;i<n;i++) {
    		int start = 0, end = n-1;
    		while(start<end) {
    			if(start==i) start++;
    			else if(end==i) end--;
    			else if(num[i] == num[start]+num[end]) {
    				ans++;
    				break;
    			}
    			else if(num[i] < num[start]+num[end]) {
    				end--;
    			}
    			else if(num[i] > num[start]+num[end]) {
    				start++;
    			}
    		}
    	}
    	System.out.println(ans);
    }
    
}
