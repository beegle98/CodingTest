

import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static int tc;
	static int n;
	static int r;
	static int[] input;   // 입력된 N개의 원소
	static int[] numbers; // 뽑은 r개를 저장한 조합 배열
	static int[] ans; // 정답
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		n = 9;
		r = 7;
		input = new int[n];
		numbers = new int[r];
		ans = new int[r];
		for(int i=0;i<n;i++) {
			input[i] = sc.nextInt();
		}
		
		comb(0, 0);
		for(int i=0;i<r;i++) System.out.println(ans[i]);
		
	}

	private static void comb(int depth, int start) {
		if(depth==r) {
			tc++;
			int sum=0;
			for(int i=0;i<r;i++) sum += numbers[i];
			if(sum==100) for(int i=0;i<r;i++) ans[i]=numbers[i];
			return;
		}
		
		for(int i=start;i<n;i++) {
			numbers[depth] = input[i];
			comb(depth+1,i+1);
		}
	}

}
