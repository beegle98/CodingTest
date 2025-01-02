import java.io.*;
import java.util.*;

public class Main {

    static class A implements Comparable<A>{
        int idx;
        int value;
        A(int idx, int value){
            this.idx = idx;
            this.value = value;
        }
        public int compareTo(A a){
            if(this.value == a.value) return this.idx - a.idx;
            return this.value - a.value;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        PriorityQueue<A> pq = new PriorityQueue<>();
        List<Integer> s = new ArrayList<>(N+1);
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int value = Integer.parseInt(st.nextToken());
            s.add(value);
            pq.add(new A(i,value));
        }
        int M = Integer.parseInt(br.readLine());
        for(int i=0;i<M;i++){
            st = new StringTokenizer(br.readLine());
            int op = Integer.parseInt(st.nextToken());
            if(op == 1){
                int idx = Integer.parseInt(st.nextToken());
                int value = Integer.parseInt(st.nextToken());
                pq.add(new A(idx-1,value));
                s.set(idx-1,value);
            }
            else{
                while(!pq.isEmpty()){
                    A a = pq.peek();
                    if (s.get(a.idx)!=a.value) pq.poll();
                    else break;
                }
                System.out.println(pq.peek().idx+1);
            }
        }

    }

}

