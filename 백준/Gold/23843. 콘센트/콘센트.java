import java.util.*;
import java.io.*;
/*
큰 것 부터 꼽는다.
작은 거 빼내면서 종료시간을 업데이트 한다.
 */
public class Main {

    static int n;
    static int m;
    static Integer[] t;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        t = new Integer[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            t[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(t, Collections.reverseOrder());

        int time = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            if (pq.size() >= m) {
                time = pq.poll();
            }

            pq.add(time + t[i]);
        }

        while (!pq.isEmpty()) {
            time = pq.poll();
        }

        System.out.println(time);
    }
}