import java.util.*;

public class Main {
    static int n, m, ans = -1;
    static String[] s;
    static boolean[][][] visited;

    static class MAP {
        int x, y, key, cnt;

        MAP(int x, int y, int key, int cnt) {
            this.x = x;
            this.y = y;
            this.key = key;
            this.cnt = cnt;
        }
    }

    static final int[] dx = {-1, 1, 0, 0};
    static final int[] dy = {0, 0, -1, 1};

    public static void bfs(int x, int y, int key, int cnt, Queue<MAP> q) {
        if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y][key]) return;

        visited[x][y][key] = true;

        if (s[x].charAt(y) == '1') { // Exit
            ans = cnt;
            q.clear(); // Clear the queue
            return;
        }
        if (s[x].charAt(y) == '#') return;
        else if (s[x].charAt(y) >= 'a' && s[x].charAt(y) <= 'f') {
            key |= 1 << (s[x].charAt(y) - 'a');
            for (int i = 0; i < 4; i++) {
                q.add(new MAP(x + dx[i], y + dy[i], key, cnt + 1));
            }
        } else if (s[x].charAt(y) >= 'A' && s[x].charAt(y) <= 'F') {
            if ((key & (1 << (s[x].charAt(y) - 'A'))) != 0) {
                for (int i = 0; i < 4; i++) {
                    q.add(new MAP(x + dx[i], y + dy[i], key, cnt + 1));
                }
            }
        } else {
            for (int i = 0; i < 4; i++) {
                q.add(new MAP(x + dx[i], y + dy[i], key, cnt + 1));
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        s = new String[n];
        visited = new boolean[n][m][65];

        for (int i = 0; i < n; i++) {
            s[i] = sc.next();
        }

        Queue<MAP> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i].charAt(j) == '0') {
                    q.add(new MAP(i, j, 0, 0));
                }
            }
        }

        while (!q.isEmpty()) {
            MAP tmp = q.poll();
            bfs(tmp.x, tmp.y, tmp.key, tmp.cnt, q);
        }

        System.out.println(ans);
        sc.close();
    }
}