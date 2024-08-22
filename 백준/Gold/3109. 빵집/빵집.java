 import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int R, C;
    static char[][] map;
    static boolean[][] visited;
    static int[] dr = {-1, 0, 1}; // 위, 오른쪽, 아래
    static int totalPaths = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        map = new char[R][C];
        visited = new boolean[R][C];
        
        for (int i = 0; i < R; i++) {
            String line = br.readLine();
            for (int j = 0; j < C; j++) {
                map[i][j] = line.charAt(j);
            }
        }

        for (int i = 0; i < R; i++) {
            if (dfs(i, 0)) {
                totalPaths++;
            }
        }

        System.out.println(totalPaths);
    }

    private static boolean dfs(int r, int c) {
        visited[r][c] = true;
        
        if (c == C - 1) { // 마지막 열에 도달하면
            return true;
        }

        for (int i = 0; i < 3; i++) {
            int nr = r + dr[i];
            int nc = c + 1;

            if (nr >= 0 && nr < R && nc < C && map[nr][nc] == '.' && !visited[nr][nc]) {
                if (dfs(nr, nc)) {
                    return true;
                }
            }
        }

        return false;
    }
}