

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static int n,k;
	static int ans = 0;
	static int[] arr = new int[100];
	
	public static void f(int x, int cnt, int check) {
		if (x >= 26) return;
		if (cnt <= 0) {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				if ((arr[i] & check) == arr[i]) sum++;
			}
			ans = max(ans, sum);
			return;
		}
		f(x + 1, cnt, check);
		if ((check & (1 << (x + 1))) == 0) f(x + 1, cnt - 1, check | (1 << (x + 1)));
	}
	
	private static int max(int a, int b) {
		if(a < b) return b;
		return a;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		
		for(int i=0;i<n;i++) {
			String s = sc.next();
			arr[i] = 0;
			for (int j = 0; j < s.length(); j++) {
				arr[i] |= 1 << (s.charAt(j) - 'a');
			}
		}
		int check = 0;
		check |= 1 << ('a' - 'a');
		check |= 1 << ('n' - 'a');
		check |= 1 << ('t' - 'a');
		check |= 1 << ('c' - 'a');
		check |= 1 << ('i' - 'a');
		
		if (k >= 5) f(0, k - 5, check);
		System.out.println(ans);
	}

}
