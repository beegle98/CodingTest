import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	private static final StringBuilder output = new StringBuilder();

	static void move(int st, int ed) {
		output.append(st).append(" ").append(ed).append("\n");
	}

	static void hanoi(int n, int st, int ed, int via) {
		if (n == 1) {
			move(st, ed);
			return;
		}
		hanoi(n - 1, st, via, ed);
		move(st, ed);
		hanoi(n - 1, via, ed, st);
	}

	static void Pow(int n) {
		BigInteger ans = new BigInteger("1");
		BigInteger x = new BigInteger("2");
		for (; n > 0; n >>= 1) {
			if (n % 2 == 1)
				ans = ans.multiply(x);
			x = x.multiply(x);

		}
		System.out.println(ans.subtract(new BigInteger("1")));
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		br.close();
		if (n <= 20) {
			output.append((long) (Math.pow(2, n) - 1)).append("\n");
			hanoi(n, 1, 3, 2);
			System.out.println(output);
		} else {
			Pow(n);
		}

	}
}