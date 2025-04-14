import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Long> a = new ArrayList<>(n);
        ArrayList<Long> sum = new ArrayList<>(n);

        StringTokenizer st = new StringTokenizer(br.readLine());
        a.add(Long.parseLong(st.nextToken()));
        sum.add(a.get(0));

        for (int i = 1; i < n; i++) {
            a.add(Long.parseLong(st.nextToken()));
            sum.add(sum.get(i - 1) + a.get(i));
        }

        long ans = 0;
        for (int i = n - 2; i >= 1; i--) {
            long valR = sum.get(i) - (sum.get(n - 1) - sum.get(i));
            int index = Collections.binarySearch(sum, valR);
            int r = (index < 0) ? -index - 1 : index;

            long valL = sum.get(n - 1) - sum.get(i);
            index = Collections.binarySearch(sum, valL);
            int l = (index < 0) ? -index - 1 : index;

            ans += Math.min(r, l);
        }

        System.out.println(ans);
    }
}

