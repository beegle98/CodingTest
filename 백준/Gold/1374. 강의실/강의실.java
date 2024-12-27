import java.io.*;
import java.util.*;

public class Main {

    static class Lecture implements Comparable<Lecture>{
        int st;
        int ed;
        Lecture(int st, int ed) {
            this.st = st;
            this.ed = ed;
        }
        public int compareTo(Lecture o) {
            if(st==o.st) return ed-o.ed;
            return st - o.st;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        List<Lecture> s = new ArrayList<>(N);
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int idx = Integer.parseInt(st.nextToken());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            s.add(new Lecture(start,end));
        }
        Collections.sort(s);
        for(int i=0;i<N;i++){
            pq.offer(s.get(i).ed);
            if(pq.peek() <= s.get(i).st) pq.poll();
        }
        System.out.println(pq.size());
    }

}
