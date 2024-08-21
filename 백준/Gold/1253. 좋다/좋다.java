
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
    		for(int j=0;j<n;j++) {
    			if(i==j) continue;
    			if(i<j) {
    				if(Arrays.binarySearch(num, i+1,j,num[i]-num[j])>=0
    						|| Arrays.binarySearch(num, j+1,n,num[i]-num[j])>=0) {
    					ans++;
    					break;
    				}
    			}
    			else {
    				if(Arrays.binarySearch(num, j+1,i,num[i]-num[j])>=0
    						|| Arrays.binarySearch(num, i+1,n,num[i]-num[j])>=0) {
    					ans++;
    					break;
    				}
    			}
    		}
    	}
    	System.out.println(ans);
    }
    
}
