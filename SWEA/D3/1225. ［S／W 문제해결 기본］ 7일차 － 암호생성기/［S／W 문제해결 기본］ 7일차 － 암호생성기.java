import java.util.*;
import java.io.*;


public class Solution {
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		List<Integer> num = new ArrayList<Integer>();
		int T = 10;
		for(int tc=1;tc<=T;tc++) {
			int N = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			int Min = Integer.MAX_VALUE;
			for(int i=0;i<8;i++) {
				num.add(Integer.parseInt(st.nextToken()));
				Min = Math.min(Min,num.get(i));
			}
			int r;
			if(Min%15 == 0) r = Min - 15;
			else r = Min - Min%15;
			
			for(int i=0;i<8;i++) {
				num.set(i,num.get(i)-r);
			}
			boolean flag = true;
			while(flag) {
				for(int i=1;i<=5;i++) {
					int first = num.remove(0);
					if(first-i <= 0) {
						num.add(0);
						flag = false;
						break;
					}
					else num.add(first-i);
				}
			}
			
			System.out.printf("#%d ",N);
			for(int i=0;i<8;i++) {
				System.out.printf("%d ",num.get(i));
			}
			System.out.println();
			num.clear();
		}
	}
	
}
