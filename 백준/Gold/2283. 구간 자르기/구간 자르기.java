import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        final int MAX = 1_000_000;
        int[] dp = new int[MAX+1];
        int[] psum = new int[MAX+1];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            dp[a]++;
            dp[b]--;
        }
        for(int i=1;i<=MAX;i++){
            dp[i] += dp[i-1];
        }
        for(int i=1;i<=MAX;i++){
            psum[i]= psum[i-1] + dp[i-1];
        }
        // psum[i] = 0~i까지의 합
        int l=0,r=1;
        int ans1=0, ans2=0;
        while(r<=MAX){
            if(psum[r]-psum[l]==k) {
                ans1 = l;
                ans2 = r;
                break;
            }else if(psum[r]-psum[l]>k){
                l++;
            }else{
                r++;
            }
        }
        System.out.println(ans1 + " " + ans2);
    }
}