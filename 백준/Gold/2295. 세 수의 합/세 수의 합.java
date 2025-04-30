import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long[] arr = new long[n];
        HashSet<Long> h = new HashSet<>();
        for(int i = 0; i < n; i++) arr[i] = Long.parseLong(br.readLine());
        Arrays.sort(arr);
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                h.add(arr[i]+arr[j]);
            }
        }
        for(int i=n-1;i>0;i--) {
            for(int j=i-1;j>=0;j--) {
                if(h.contains(arr[i]-arr[j])){
                    System.out.println(arr[i]);
                    return;
                }
            }
        }
    }
}

