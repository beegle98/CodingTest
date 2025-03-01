import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[][] cows = new int[n][2];
        Set<Integer> xSet = new HashSet<>();
        Set<Integer> ySet = new HashSet<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            cows[i][0] = x;
            cows[i][1] = y;
            xSet.add(x);
            ySet.add(y);
        }

        // 좌표 압축을 위해 x, y 좌표 추출 및 정렬
        List<Integer> xList = new ArrayList<>(xSet);
        List<Integer> yList = new ArrayList<>(ySet);
        Collections.sort(xList);
        Collections.sort(yList);

        // 좌표 압축 (좌표 -> 인덱스 매핑)
        Map<Integer, Integer> xMap = new HashMap<>();
        Map<Integer, Integer> yMap = new HashMap<>();

        for (int i = 0; i < xList.size(); i++) {
            xMap.put(xList.get(i), i);
        }

        for (int i = 0; i < yList.size(); i++) {
            yMap.put(yList.get(i), i);
        }

        // 압축된 좌표로 소의 위치 변환
        int[][] compressedCows = new int[n][2];
        for (int i = 0; i < n; i++) {
            compressedCows[i][0] = xMap.get(cows[i][0]);
            compressedCows[i][1] = yMap.get(cows[i][1]);
        }

        // 2D 누적합 배열 초기화 (압축된 좌표 공간)
        int maxX = xList.size();
        int maxY = yList.size();
        int[][] prefixSum = new int[maxX + 1][maxY + 1];

        // 소의 위치에 1 표시
        for (int[] cow : compressedCows) {
            prefixSum[cow[0] + 1][cow[1] + 1]++;
        }

        // 2D 누적합 계산
        for (int i = 1; i <= maxX; i++) {
            for (int j = 1; j <= maxY; j++) {
                prefixSum[i][j] += prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
            }
        }

        // 모든 가능한 울타리 위치에 대해 최소 M 찾기
        int minMaxCows = n;  // 최악의 경우 모든 소가 한 영역에 있음

        for (int i = 0; i < maxX; i++) {
            for (int j = 0; j < maxY; j++) {
                // 4개 영역의 소의 수 계산
                int topLeft = prefixSum[i][j];
                int topRight = prefixSum[maxX][j] - topLeft;
                int bottomLeft = prefixSum[i][maxY] - topLeft;
                int bottomRight = n - topLeft - topRight - bottomLeft;

                // 4개 영역 중 최대 소의 수
                int maxCows = Math.max(Math.max(topLeft, topRight), Math.max(bottomLeft, bottomRight));
                minMaxCows = Math.min(minMaxCows, maxCows);
            }
        }

        System.out.println(minMaxCows);
    }
}
