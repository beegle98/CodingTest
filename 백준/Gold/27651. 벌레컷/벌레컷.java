import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] a = new long[n+1];
        long[] sum = new long[n+1];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= n; i++) {
            a[i] = Long.parseLong(st.nextToken());
            sum[i] = sum[i - 1] + a[i];
        }

        long ans = 0;
        int l=0,r=n-1;
        while(l<r){
            while(sum[l+1] < sum[n]-sum[r] && sum[r]-sum[l+1] > sum[n]-sum[r]) l++;
            //System.out.println(l + " " + r);
            ans += l;
            r--;
            while(l>0 && sum[r]-sum[l] <= sum[n]-sum[r] ) l--;
        }

        System.out.println(ans);
    }
}