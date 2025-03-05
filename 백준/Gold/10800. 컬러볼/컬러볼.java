import java.io.*;
import java.util.*;

class Ball implements Comparable<Ball> {
    int color;
    int size;
    int index;

    Ball(int color, int size, int index) {
        this.color = color;
        this.size = size;
        this.index = index;
    }

    @Override
    public int compareTo(Ball o) {
        if (this.size == o.size) return this.color - o.color;
        return this.size - o.size;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Ball[] arr = new Ball[n];
        int[] ans = new int[n];
        int[] cnt = new int[200001];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            arr[i] = new Ball(x, y, i);
        }

        Arrays.sort(arr);

        int psum = arr[0].size, sum = 0;
        cnt[arr[0].color] += psum;

        for (int i = 1; i < n; i++) {
            int idx = arr[i].index;
            int color = arr[i].color;
            int size = arr[i].size;

            if (size > arr[i - 1].size) {
                sum += psum;
                psum = 0;
            }
            if (size == arr[i - 1].size && color == arr[i - 1].color) {
                ans[idx] = ans[arr[i - 1].index];
            } else {
                ans[idx] = sum - cnt[color];
            }
            psum += size;
            cnt[color] += size;
        }

        for (int i = 0; i < n; i++) {
            System.out.println(ans[i]);
        }
    }
}
