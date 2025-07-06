import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        final int MAX = 100_000;
        int n = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        long[] time = new long[MAX + 1];
        for (int i = 0; i < n; i++) {
            int m = Integer.parseInt(br.readLine());
            for (int j = 0; j < m; j++) {
                st = new StringTokenizer(br.readLine());
                int start = Integer.parseInt(st.nextToken());
                int end = Integer.parseInt(st.nextToken());
                time[start]++;
                time[end]--;
            }
        }
        for (int i = 1; i <= MAX; i++) {
            time[i] += time[i - 1];
        }
        for (int i = 1; i <= MAX; i++) {
            time[i] += time[i - 1];
        }
        long ans = time[t-1], s = 0, e = t;
        for (int i = 1; i <= MAX - t; i++) {
            if (ans < time[i + t - 1] - time[i - 1]) {
                ans = time[i + t - 1] - time[i - 1];
                s = i;
                e = i + t;
            }
        }
        System.out.println(s + " " + e);
    }
}