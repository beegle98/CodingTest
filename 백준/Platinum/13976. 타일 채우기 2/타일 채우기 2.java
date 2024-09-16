import java.io.*;

/**
 * f(n) = 4*f(n-2)-f(n-4)를 구한 후 행렬 식으로 변경해서 f(n) = ((4, -1),(1,0))^(n/2-1) * (f(2), f(0)) 로 유도
 * 이후 분할 정복으로 행렬의 제곱을 구해서 처리
 */
public class Main {

    static long N;
    static long M = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Long.parseLong(br.readLine());

        if (N % 2 != 0) {
            System.out.println(0);
        } else {
            long[] baseCase = {3, 1};// d[2], d[0]
            if (N == 2) {
                System.out.println(3);
            } else {
                System.out.println(multiMatrix(getPower(new long[][] {{4, -1}, {1, 0}}, N / 2 - 1), baseCase));
            }
        }
    }
    //분할 정복을 이용해서 제곱수 빠르게 구하기 - log n 처리
    static long[][] getPower(long[][] matrix, long n) {
        if (n == 1) {
            return matrix;
        } else {
            if (n % 2 == 0) {
                long[][] part = getPower(matrix, n / 2);
                return multiMatrix(part, part);
            } else {
                return multiMatrix(getPower(matrix, n - 1), matrix);
            }
        }
    }
    //2차원 * 2차원 행렬의 곱 처리
    static long[][] multiMatrix(long[][] a, long[][] b) {
        long[][] multi = new long[2][2];
        multi[0][0] = getMod(a[0][0], b[0][0], a[0][1], b[1][0]);
        multi[0][1] = getMod(a[0][0], b[0][1], a[0][1], b[1][1]);
        multi[1][0] = getMod(a[1][0], b[0][0], a[1][1], b[1][0]);
        multi[1][1] = getMod(a[1][0], b[0][1], a[1][1], b[1][1]);
        return multi;
    }
 
    // 마지막 2차원 * 1차원 행렬의 곱 처리, 1차원 배열이 나오지만 거기서 d[n]에 해당하는 첫 번째 값만 필요하므로 그 녀석만 long으로 반환
    static long multiMatrix(long[][] a, long[] b) {
        return getMod(a[0][0], b[0], a[0][1], b[1]);
    }
    // 결과가 음수일 경우를 대비해서 M을 더한 후 처리
    static long getMod(long a, long b, long c, long d) {  
        return ((a * b % M) + (c * d % M) + M) % M;
    }
}