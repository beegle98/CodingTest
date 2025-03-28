import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            int[] s = new int[n+1];
            st = new StringTokenizer(br.readLine());
            for(int i=0;i<n;i++){
                arr[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr);
            s[0]=arr[0];
            s[n]=arr[0];
            int l=1,r=n-1;
            for(int i=1;i<n;i++){
                if(i%2==1){
                    s[l++]=arr[i];
                }else{
                    s[r--]=arr[i];
                }
            }
            int ans = 0;
            for(int i=1;i<=n;i++){
                ans = Math.max(ans,Math.abs(s[i]-s[i-1]));
            }
            System.out.println(ans);
        }
    }

}