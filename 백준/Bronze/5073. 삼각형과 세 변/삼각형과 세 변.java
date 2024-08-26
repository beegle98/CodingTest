
import java.util.*;
import java.io.*;
/*
 * DP
 * 메모리 : 14308KB
 * 시간    : 100ms
 * 
 * DFS
 * 메모리: 16544KB
 * 시간   : 320ms
 */
public class Main {
		
		
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int[] s = new int[3];
    	while(true) {
    		StringTokenizer st = new StringTokenizer(br.readLine());
        	for(int i=0;i<3;i++) {
        		s[i] = Integer.parseInt(st.nextToken());
        	}
        	if(s[0]+s[1]+s[2]==0) break;
        	Arrays.sort(s);
        	if(s[2] >= s[0]+s[1]) System.out.println("Invalid");
        	else if(s[0]==s[1] && s[1]==s[2]) System.out.println("Equilateral");
        	else if(s[0]==s[1] || s[0]==s[2] || s[1]==s[2]) System.out.println("Isosceles");
        	else System.out.println("Scalene");
    	}
    }
}