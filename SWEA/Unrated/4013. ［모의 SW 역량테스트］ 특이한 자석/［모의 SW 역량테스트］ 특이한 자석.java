import java.io.*;
import java.util.*;

public class Solution {
	static int k;
	static int[][] arr;
	static int[] s;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        for(int tc=1;tc<=t;tc++) {
        	
        	k = Integer.parseInt(br.readLine());
        	arr = new int[5][8];
        	s = new int[5];
        	for(int i=1;i<=4;i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j=0;j<8;j++) arr[i][j] = Integer.parseInt(st.nextToken());
        	}
        	for(int i=0;i<k;i++) {
        		st = new StringTokenizer(br.readLine());
        		int a = Integer.parseInt(st.nextToken());
        		int b = Integer.parseInt(st.nextToken());
        		//System.out.println(i);
        		if(a!=1 && arr[a][MOD(s[a],-2)]!=arr[a-1][MOD(s[a-1],2)]) sol1(a-1, b*-1);
        		if(a!=4 && arr[a][MOD(s[a],2)]!=arr[a+1][MOD(s[a+1],-2)]) sol2(a+1, b*-1);
        		s[a]=(s[a]-b+8)%8;
        	}
        	int ans = 0;
        	for(int i=1;i<=4;i++) {
        		if(arr[i][s[i]]==1) ans += (int)Math.pow(2, i-1);
        	}
        	System.out.println("#"+tc+" "+ans);
        }
        
    }
	private static void sol2(int i, int r) {
		if(i==4) {
			s[i]=(s[i]-r+8)%8;
			return;
		}
		if(arr[i][MOD(s[i],2)]!=arr[i+1][MOD(s[i+1],-2)]) {
			sol2(i+1,r*-1);
		}
		// 돌려줌 = 시작지점 반대로 한칸 이동
		s[i]=(s[i]-r+8)%8;
		//System.out.println(i + " " + r);
	}
	private static void sol1(int i, int r) {
		if(i==1) {
			s[i]=(s[i]-r+8)%8;
			return;
		}
		if(arr[i][MOD(s[i],-2)]!=arr[i-1][MOD(s[i-1],2)]) {
			sol1(i-1,r*-1);
		}
		// 돌려줌 = 시작지점 반대로 한칸 이동
		s[i]=(s[i]-r+8)%8;
		//System.out.println(i + " " + r);
	}
	private static int MOD(int a,int b) {return (a+b+8)%8;} 
}
