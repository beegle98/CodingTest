import java.util.*;
import java.awt.font.ShapeGraphicAttribute;
import java.io.*;

public class Main {
	private static class BabyShark{
		int speed;
		int dir; // dir%4 = 0 왼쪽 , 1 위쪽, 2 아래쪽, 3 오른쪽
		int size;
		public BabyShark(int speed, int dir, int size) {
			this.speed = speed;
			this.dir = dir;
			this.size = size;
		}
	}
	static int R,C,M,sum=0;
	static BabyShark[][] MAP;
	static BabyShark[][] tempMAP;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken()); // 행
		C = Integer.parseInt(st.nextToken()); // 열
		M = Integer.parseInt(st.nextToken()); // 상어 수
		MAP = new BabyShark[R+1][C+1];
		for(int i=0;i<M;i++) {
			int r,c,s,d,z;
			st = new StringTokenizer(br.readLine());
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			z = Integer.parseInt(st.nextToken());
			MAP[r][c] = new BabyShark(s, d%4, z);
		}
		for(int t=1;t<=C;t++) {
			Kill(t);
			tempMAP = new BabyShark[R+1][C+1];
			for(int i=1;i<=R;i++) {
				for(int j=1;j<=C;j++) {
					if(MAP[i][j]!=null) MoveShark(i,j);
				}
			}
			MAP = tempMAP;
		}
		System.out.println(sum);
	}
	private	static void Kill(int c) {
		for(int i=1;i<=R;i++) {
			if(MAP[i][c]!=null) {
				sum += MAP[i][c].size;
				MAP[i][c]=null;
				return;
			}
		}
	}
	private	static void MoveShark(int r,int c) {
		BabyShark tmp = MAP[r][c];
		int x = tmp.speed; // 총 이동 거리
		if(tmp.dir==0) { // 왼
			x %= 2*(C-1);
			if(x>c-1) {
				x-= c-1;
				tmp.dir = 3 - tmp.dir;
				if(x>C-1) {
					x -= (C-1);
					c = C - x;
					tmp.dir = 3 - tmp.dir;
				}
				else c = 1+x;
			}else c -= x;
		}else if(tmp.dir==1) { // 위
			x %= 2*(R-1);
			if(x>r-1) {
				x-= r-1;
				tmp.dir = 3 - tmp.dir;
				if(x>R-1) {
					x -= (R-1);
					r = R - x;
					tmp.dir = 3 - tmp.dir;
				}
				else r = 1+x;
			}else r -= x;
		}else if(tmp.dir==2) { // 아래
			x %= 2*(R-1);
			if(x>R-r) {
				x-= R-r;
				tmp.dir = 3 - tmp.dir; // 방향 전환
				if(x>R-1) {
					x -= R-1;
					r = 1 + x;
					tmp.dir = 3 - tmp.dir;
				}
				else r = R-x;
			}else r += x;
		}else if(tmp.dir==3) { // 오
			x %= 2*(C-1);
			if(x>C-c) {
				x-= C-c;
				tmp.dir = 3 - tmp.dir; // 방향 전환
				if(x>C-1) {
					x -= C-1;
					c = 1 + x;
					tmp.dir = 3 - tmp.dir;
				}
				else c = C-x;
			}else c += x;
		}
		if(tempMAP[r][c]==null) {
			tempMAP[r][c] = tmp;
		}else if(tempMAP[r][c].size < tmp.size) {
			tempMAP[r][c]=tmp;
		}
	}
}
