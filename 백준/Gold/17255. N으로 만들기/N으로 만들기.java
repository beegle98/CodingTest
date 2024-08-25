import java.util.*;
import java.io.*;

public class Main {
		
		static String Num;
		static int ans=0;
	
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	//StringTokenizer st = new StringTokenizer(br.readLine());
    	Num = br.readLine();
    	recur(Num);
    	System.out.println(ans);
    }
    private static void recur(String str) {
    	int len = str.length();
    	if(len==1) {
    		ans++;
    		return;
    	}
    	String str0 = str.substring(0,len-1);
    	String str1 = str.substring(1,len);
    	recur(str0);
    	if(str0.equals(str1)) return;
    	recur(str1);
    }
	
}


