import java.util.*;
import java.io.*;

public class Main {
	private static final StringBuilder output = new StringBuilder();
	static void move(int st,int ed) {
		output.append(st).append(" ").append(ed).append("\n");
	}
	static void hanoi(int n,int st,int ed,int via) {
		if(n==1){
			move(st,ed);
			return;
		}
		hanoi(n-1,st,via,ed);
		move(st,ed);
		hanoi(n-1,via,ed,st);
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	    int n=Integer.parseInt(br.readLine());
	    br.close();
	    output.append((int) (Math.pow(2, n) - 1)).append("\n");
		hanoi(n,1,3,2);
		System.out.println(output);
	}
}
