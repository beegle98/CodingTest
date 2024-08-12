import java.io.*;
import java.util.*;

class Example implements Comparable<Example>{

	private int num;
	public Example(int num) {
		this.num = num;
	}
	
	public int getNum() {
		return num;
	}

	@Override
	public int compareTo(Example ex) {
		if(Math.abs(this.num) == Math.abs(ex.num)) {
			return this.num - ex.num;
		}
		else {
			return Math.abs(this.num) - Math.abs(ex.num);
		}
	}
	
}

public class Main {
	
	static PriorityQueue<Example> pq = new PriorityQueue<>();
	
	
	public static void main(String[] args) throws IOException{
		
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		for(int i=0;i<n;i++) {
			int x = sc.nextInt();
			if(x==0) {
				if(pq.isEmpty()) System.out.println(0);
				else System.out.println(pq.poll().getNum());
			}else {
				Example tmp = new Example(x);
				pq.add(tmp);
			}
			
			
		}
	
	}

}
