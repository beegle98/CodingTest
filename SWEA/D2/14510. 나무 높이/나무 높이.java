
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;



public class Solution {
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		
		
		int T = Integer.parseInt(br.readLine());
		int[] s= new int[101];
		
		for(int tc=1;tc<=T;tc++) {
			int Max = 0;
			int sumA = 0, sumB = 0, ans = 0;
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				s[i] = Integer.parseInt(st.nextToken());
				Max = Math.max(Max, s[i]);
			}
			for(int i=0;i<n;i++) {
				s[i] = Max - s[i];
				sumA += s[i]/2;
				sumB += s[i]%2;
			}
			if(sumA < sumB) ans += sumB*2 - 1;
			else if(sumA == sumB) ans += sumB*2;
			else { // sumA > sumB
				ans += sumB*2;
				sumA -= sumB;
				ans += (sumA/3) * 4;
				sumA %=3;
				if(sumA==1) ans+=2;
				else if(sumA==2) ans +=3;
			}
			
			System.out.printf("#%d %d\n",tc,ans);
		}
	}
	
}

