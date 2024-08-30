import java.io.*;
import java.util.*;

public class Solution {

    private static int n;
    private static int[][] arr;
    private static List<int[]> core; // 코어 위치 저장 리스트
    private static final int[] dx = {1, -1, 0, 0};
    private static final int[] dy = {0, 0, -1, 1};

    private static int maxCore = 20;
    private static int minSum = 0;

    private static boolean check(int x, int y, int d) { // (x,y) 좌표에서 d 방향으로 연결할 수 있는지 확인
        x += dx[d];
        y += dy[d];
        while (x >= 0 && x < n && y >= 0 && y < n) {
            if (arr[x][y] == 1) return false;
            x += dx[d];
            y += dy[d];
        }
        return true; // 연결 가능
    }

    private static void recur(int index, int coreCnt, int wireSum) {
        if (index == core.size()) {
            if (maxCore < coreCnt) { // 코어 수가 더 많으면 무조건 갱신
                maxCore = coreCnt;
                minSum = wireSum;
            } else if (maxCore == coreCnt) {
                minSum = Math.min(minSum, wireSum); // 코어 수가 같으므로 sum 크기 비교
            }
            return;
        }
        int x = core.get(index)[0]; // core X 좌표
        int y = core.get(index)[1]; // core Y 좌표

        for (int i = 0; i < 4; i++) { // 4 방향
            if (check(x, y, i)) { // 연결할 수 있는지 확인
                int nx = x + dx[i], ny = y + dy[i];
                int sum = 0;
                while (nx >= 0 && nx < n && ny >= 0 && ny < n) { // 전선 연결
                    arr[nx][ny] = 1;
                    sum++;
                    nx += dx[i];
                    ny += dy[i];
                }
                recur(index + 1, coreCnt + 1, wireSum + sum);
                nx = x + dx[i];
                ny = y + dy[i];
                while (nx >= 0 && nx < n && ny >= 0 && ny < n) { // 연결 해제
                    arr[nx][ny] = 0;
                    nx += dx[i];
                    ny += dy[i];
                }
            }
        }
        recur(index + 1, coreCnt, wireSum);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            n = Integer.parseInt(br.readLine());
            arr = new int[n][n];
            core = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                    if (i != 0 && i != n - 1 && j != 0 && j != n - 1 && arr[i][j] == 1) { // 가장자리 코어는 저장 X
                        core.add(new int[]{i, j});
                    }
                }
            }

            minSum = 10000;
            maxCore = 0;

            recur(0, 0, 0);

            sb.append("#").append(tc).append(" ").append(minSum).append("\n");
        }
        System.out.print(sb.toString());
    }
}
