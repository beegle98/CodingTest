import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        ArrayList<Long> v = new ArrayList<>();
        long ans = 0;

        for (int i = 0; i < n; i++) {
            long sum = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int x = Integer.parseInt(st.nextToken());
                sum += x;
            }
            v.add(sum);
            ans += sum;
        }

        Collections.sort(v);
        ans /= 2;
        for (int i = 0; i < n / 2; i++) {
            ans -= v.get(i);
        }
        System.out.println(ans);
    }
}
