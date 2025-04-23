import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        int max = 0;
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            max = Math.max(max, arr[i]);
        }
        int ans = 0;
        int l=max,r=1_000_000_000, mid;
        while(l<=r) {
            mid = (l+r)/2;
            int cnt = 1, sum = 0;
            for (int j = 0; j < n; j++) {
                sum += arr[j];
                if (sum > mid) {
                    sum = arr[j];
                    cnt++;
                }
            }
            if (cnt <= m) {
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        System.out.println(ans);
    }
}
