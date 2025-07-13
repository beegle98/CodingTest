import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int ans = 0;
        long MIN = Long.MAX_VALUE;
        long[] arr = new long[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
            arr[i] += arr[i-1];
        }
        for (int k = 1; k <= n / 2; k++) {
            for (int i = k; i <= n; i++) {
                for (int j = i + k; j <= n; j++) {
                    long sub = Math.abs((arr[i] - arr[i - k]) - (arr[j] - arr[j - k]));
                    if (sub <= MIN) {
                        MIN = sub;
                        ans = k;
                    }
                }
            }
        }
        System.out.println(ans);
        System.out.println(MIN);
    }
}