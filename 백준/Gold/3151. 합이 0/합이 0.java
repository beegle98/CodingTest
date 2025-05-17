import java.io.*;
import java.util.*;

public class Main {

    static int[] arr;
    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        long ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = arr[i] + arr[j];
                int l = lower(j+1,n-1,-sum);
                int r = upper(j+1,n-1,-sum);
                ans += r - l;
            }
        }
        System.out.println(ans);
    }
    static int lower(int l,int r, int key){
        while(l<=r){
            int m = (l+r)/2;
            if(arr[m]<key) {
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return l;
    }
    static int upper(int l, int r, int key){
        while(l<=r){
            int m = (l+r)/2;
            if(arr[m]<=key) {
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return l;
    }
}
