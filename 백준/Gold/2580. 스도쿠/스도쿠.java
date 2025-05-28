import java.io.*;
import java.util.*;

public class Main {

    static int[][] map = new int[9][9];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        for(int i=0;i<9;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<9;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        sudoku(0,0);
    }
    static void sudoku(int x,int y) {
        if (x == 9) {
            printSudoku();
            System.exit(0);
        }
        if (map[x][y] != 0) {
            sudoku(x + (y + 1) / 9, (y + 1) % 9);
            return;
        }
        for (int i = 1; i <= 9; i++) {
            // i 값이 가능한지 검사
            if (check(x, y, i)) {
                map[x][y] = i;
                sudoku(x + (y + 1) / 9, (y + 1) % 9);
            }
        }
        map[x][y] = 0;
    }
    static void printSudoku(){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                System.out.print(map[i][j]+" ");
            }
            System.out.println();
        }
    }
    static boolean check(int x, int y, int k) {
        // 행 검사
        for (int i = 0; i < 9; i++) {
            if (map[x][i] == k) {
                return false;
            }
        }

        // 열 검사
        for (int i = 0; i < 9; i++) {
            if (map[i][y] == k) {
                return false;
            }
        }

        // 3*3 칸 검사
        int nx = (x / 3) * 3;
        int ny = (y / 3) * 3;
        for (int i = nx; i < nx + 3; i++) {
            for (int j = ny; j < ny + 3; j++) {
                if (map[i][j] == k) {
                    return false;
                }
            }
        }
        
        return true;
    }
}
