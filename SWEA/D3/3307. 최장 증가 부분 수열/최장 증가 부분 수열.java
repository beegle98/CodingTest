import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        for(int tc=1;tc<=t;tc++) {
        	int n = Integer.parseInt(br.readLine());
        	st = new StringTokenizer(br.readLine());
            int[] v = new int[n];
            for (int i = 0; i < n; i++) {
                v[i] = Integer.parseInt(st.nextToken());
            }

            List<Integer> LIS = new ArrayList<>();
            LIS.add(v[0]);

            for (int i = 1; i < n; i++) {
                if (LIS.get(LIS.size() - 1) < v[i]) {
                    LIS.add(v[i]);
                } else {
                    
                    int index = Collections.binarySearch(LIS, v[i]);
                    if (index < 0) index = -(index + 1);
                    LIS.set(index, v[i]);
                }
            }

            System.out.println("#" + tc+" "+ LIS.size());
        }
        

    }
}
