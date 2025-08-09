import java.io.*;

public class Main {
    static int n, k;
    static String[] s = new String[16];
    static long[][] dp = new long[1 << 15][100];
    static int[] cache = new int[51];
    static int[] cachestr = new int[15];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            s[i] = br.readLine();
        }

        k = Integer.parseInt(br.readLine());

        // 초기 DP 설정
        dp[0][0] = 1;

        cache[0] = 1 % k;
        for (int i = 1; i < 51; i++)
            cache[i] = (cache[i - 1] * 10) % k;

        for (int i = 0; i < n; i++)
            cachestr[i] = get_mod(s[i], k);

        solve();

        long denominator = 1;
        long numerator = dp[(1 << n) - 1][0];

        for (int i = 1; i <= n; i++)
            denominator *= i;

        long gcd = GCD(numerator, denominator);

        System.out.println((numerator / gcd) + "/" + (denominator / gcd));
    }
    // 문자열 s를 div로 나눈 나머지
    static int get_mod(String str, int div) {
        int ret = 0;
        for (int i = 0; i < str.length(); i++) {
            ret *= 10;
            ret += str.charAt(i) - '0';
            ret %= div;
        }
        return ret;
    }

    // 최대공약수(GCD)
    static long GCD(long lhs, long rhs) {
        long big = Math.max(lhs, rhs);
        long small = Math.min(lhs, rhs);

        while (small != 0) {
            long remainder = big % small;
            big = small;
            small = remainder;
        }
        return big;
    }

    // DP 진행
    static void solve() {
        for (int cur = 0; cur < (1 << n); cur++) {
            for (int i = 0; i < n; i++) {
                if ((cur & (1 << i)) == 0) {
                    int nextState = cur | (1 << i);
                    for (int j = 0; j < k; j++) {
                        int nextK = ((j * cache[s[i].length()]) % k + cachestr[i]) % k;
                        dp[nextState][nextK] += dp[cur][j];
                    }
                }
            }
        }
    }
}
