import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeSet;

class Node{ // 221, 1225
	int s, e;

	public Node(int sm, int sd, int em, int ed) {
		super();
		this.s=100*sm+sd;
		this.e=100*em+ed;
	}
}

public class Main {
	
	static int N;
	static PriorityQueue<Node> pq;
		
    public static void main(String[] args) throws NumberFormatException, IOException {
    	init();
    	proc();
    }

	public static void init() throws NumberFormatException, IOException {
    	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    	N=Integer.parseInt(br.readLine());
    	pq=new PriorityQueue<>((a,b)->{
    		return Integer.compare(a.s, b.s);
    	});
    	for (int i = 0; i < N; i++) {
    		StringTokenizer st=new StringTokenizer(br.readLine());
				int sm=Integer.parseInt(st.nextToken());
				int sd=Integer.parseInt(st.nextToken());
				int em=Integer.parseInt(st.nextToken());
				int ed=Integer.parseInt(st.nextToken());
				pq.add(new Node(sm,sd,em,ed));
			}
    }
	
	
    public static void proc() {
    	int cnt=0;
    	int today=301;
    	int end=1201;
    	int maxEnd=0;
    	while(!pq.isEmpty()&&today<end) {
    		boolean found=false;
    		
    		//point
    		while(!pq.isEmpty()&&pq.peek().s<=today) {
    			Node n=pq.poll();
    			if(maxEnd<n.e) {
    				maxEnd=n.e;
    				found=true;
    			}
    		}
    		
    		if(!found) {
    			System.out.println(0);
    			return;
				}
    		
    		today=maxEnd;
    		cnt++;
    	}
    	
    	if(today<end) {
    		System.out.println(0);
    		return;
    	}
    	System.out.println(cnt);
    }
 
}