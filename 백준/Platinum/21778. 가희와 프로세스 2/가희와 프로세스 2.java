import java.io.*;
import java.util.*;

public class Main {
    static class Process {
        long id, time, prio;
        Process(long id, long time, long prio) {
            this.id = id;
            this.time = time;
            this.prio = prio;
        }
    }

    static final long LIM = 1_000_000_000_001L;
    static final long INF = 8_000_000_000_000L;
    static Process[] arr;
    static int n, Q;
    static Map<Long, Long> dp = new HashMap<>();
    static List<Long> v = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        Q = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        arr = new Process[n];
        for(int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            long id = Long.parseLong(st.nextToken());
            long time = Long.parseLong(st.nextToken());
            long prio = Long.parseLong(st.nextToken()) + LIM;
            arr[i] = new Process(id, time, prio);
        }

        Arrays.sort(arr, (a, b) -> Long.compare(a.id, b.id));

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<Q; i++) {
            long t = Long.parseLong(br.readLine());
            gahui(t, sb);
        }
        System.out.print(sb);
    }

    // 판별 함수
    static long f(long x) {
        if(dp.containsKey(x)) return dp.get(x);
        long tot = 0;
        for(Process m : arr) {
            long s = m.prio - m.time + 1;
            long e = m.prio;
            if(x <= s) tot += m.time;
            else if(s < x && x <= e) tot += (e - x + 1);
        }
        dp.put(x, tot);
        return tot;
    }

    static void gahui(long t, StringBuilder sb) {
        long le = 0, ri = INF, mid = 0;
        v.clear();
        while(le <= ri) {
            mid = (le + ri) / 2;

            if(f(mid) >= t) {
                long tot_T = f(mid + 1);
                if(tot_T < t) {
                    long r = t - tot_T;
                    for(Process p : arr) {
                        long lower = p.prio - p.time;
                        if(lower < mid  && mid <= p.prio) {
                            v.add(p.id);
                        }
                    }
                    sb.append(v.get((int)(r-1))).append('\n');
                    break;
                } else {
                    le = mid + 1;
                }
            } else {
                ri = mid - 1;
            }
        }
    }
}
