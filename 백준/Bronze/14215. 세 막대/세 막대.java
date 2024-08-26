
import java.util.*;
import java.io.*;

public class Main {
		
		
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] s = new int[3];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < 3; i++) {
			s[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(s);
		if (s[2] >= s[0] + s[1])
			System.out.println((s[0] + s[1]) * 2 - 1);
		else
			System.out.println(s[0] + s[1] + s[2]);
	}
}