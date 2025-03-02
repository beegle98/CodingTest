import java.io.*;
import java.util.*;

public class Main {

    static long[] sum = new long[55];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        sum[0]=1;
        for(int i=1;i<55;i++){
            sum[i] = sum[i-1] * 2 + (1L<<i);
        }
        System.out.println(getCount(b)-getCount(a-1));
    }
    private static long getCount(long x){
        long res = x & 1;
        for(int i=54; i>0;i--){
            if((x&(1L<<i))>0){
                res += sum[i-1] + (x-(1L<<i)+1);
                x-= 1L <<i;
            }

        }
        return res;
    }
}
