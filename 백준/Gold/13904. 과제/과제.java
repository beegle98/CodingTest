import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

class num implements Comparable<num>{
	int x;//남은 일수
	int y;//점수
	public num(int x, int y) {
		this.x = x;
		this.y = y;
	}
	@Override
	public int compareTo(num o) {
		if(this.x == o.x) {
			return  o.y - this.y;
		}else return o.x-this.x;
	}
	
}
public class Main {
	

	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		ArrayList<num> s =new ArrayList<>();
		PriorityQueue<num> pq = new PriorityQueue<>(comp2);
		
		for(int i=0;i<n;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			s.add(new num(x,y));
		}
		Collections.sort(s);
		
		int time = s.get(0).x;
		
		int sum=0,index=0;
		while(time>0) {
			if(index >= s.size() || time > s.get(index).x) {
				time--;
				if(!pq.isEmpty()) {
					sum+=pq.poll().y;
					//System.out.println(sum);
				}
			}else {
				pq.add(new num(s.get(index).x,s.get(index).y));
				index++;
				
			}
		}
		System.out.println(sum);
	}
	public static Comparator<num> comp2 = new Comparator<num>() {
		@Override
		public int compare(num o1, num o2) {
			return o2.y- o1.y;
		}
	};
}
