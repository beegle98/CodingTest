import java.io.*;
import java.util.*;

public class Solution {

	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = 10;
		
		int N,ans;
		String str;
		Stack<Character> st = new Stack<>();
		
		for(int tc=1;tc<=T;tc++) {
			N = Integer.parseInt(br.readLine());
			str = br.readLine();
			ans=1;
			for(int i=0;i<N;i++) {
				char c = str.charAt(i);
				if(c==')') {
					if(st.peek()=='(') st.pop();
					else ans = 0;
				}else if(c==']') {
					if(st.peek()=='[') st.pop();
					else ans = 0;
				}else if(c=='}') {
					if(st.peek()=='{') st.pop();
					else ans = 0;
				}else if(c=='>') {
					if(st.peek()=='<') st.pop();
					else ans = 0;
				}else {
					st.push(c);
				}
			}
			if(!st.empty()) ans=0;
			st.clear();
			System.out.printf("#%d %d\n", tc,ans);
			
		}
	}

}
