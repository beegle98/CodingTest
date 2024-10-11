
import java.util.*;
import java.io.*;

public class Main {
    
    public static int ans,pi[];
    public static String all,pattern;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
        all = br.readLine();
        pattern = br.readLine();

        pi = new int[pattern.length()];

        getPi();
        kmp();
        if(ans>0) System.out.println("1");
        else System.out.println("0");

    }

    // 패턴 일치 저장 배열
    public static void getPi(){
        int j = 0; 
        for(int i = 1; i < pattern.length(); i++){
            while(j > 0 && pattern.charAt(i) != pattern.charAt(j)){
                j = pi[j-1];
            }
            if(pattern.charAt(i) == pattern.charAt(j)){
                pi[i] = ++j;
            }
        }
    }
    
    public static void kmp(){
        // 패턴 내 일치체크 idx
        int j = 0;
        // 전체 문자열 돌기
		for (int i = 0; i < all.length(); i++) {
			// 맞는 위치가 나올 때까지 j - 1칸의 공통 부분 위치로 이동
			while(j > 0 && all.charAt(i) != pattern.charAt(j)) {
				j = pi[j - 1];
			}
			// 맞는 경우 패턴의 끝까지 확인했으면 정답
			if(all.charAt(i) == pattern.charAt(j)) {
				if(j == pattern.length() - 1) {
					ans++;			
                    j = pi[j];
				}else{
                    j++;
                }
			}
		}
    }
}