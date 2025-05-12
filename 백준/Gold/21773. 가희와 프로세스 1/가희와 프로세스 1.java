import java.io.*;
import java.util.*;

public class Main {

    static class Process implements Comparable<Process> {
        int id;
        int time;
        int priority;
        Process(int id, int time, int priority){
            this.id = id;
            this.time = time;
            this.priority = priority;
        }

        @Override
        public int compareTo(Process o) {
            if(this.priority == o.priority) return this.id - o.id;
            return o.priority - this.priority;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        PriorityQueue<Process> pq = new PriorityQueue<>();
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            pq.offer(new Process(a,b,c));
        }
        for(int i=0;i<T;i++){
            Process pop = pq.poll();
            if(pop.time>1) pq.offer(new Process(pop.id,pop.time-1,pop.priority-1));
            sb.append(pop.id + "\n");
        }
        System.out.println(sb);
    }
}