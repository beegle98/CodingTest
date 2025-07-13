import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = 0;
        long MIN = Long.MAX_VALUE;
        long[] arr = new long[n+1];
        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=n;i++){
            int x = Integer.parseInt(st.nextToken());
            arr[i] = arr[i-1] + x;
        }
        for (int i = 1; i <= n / 2; i++) {
            for (int j = i; j <= n; j++) {
                for (int l = j + i; l <= n; l++) {
                    long sub = Math.abs((arr[j] - arr[j - i]) - (arr[l] - arr[l - i]));
                    if (sub <= MIN) {
                        MIN = sub;
                        k = i;
                    }
                }
            }
        }
        System.out.println(k);
        System.out.println(MIN);
    }
}