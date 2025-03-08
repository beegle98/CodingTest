import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int ans;
        if(n==1) ans=1;
        else if(n==2) ans = Math.min(4,(m+1)/2);
        else if(m<=6) ans = Math.min(4,m);
        else ans = m-2;
        System.out.println(ans);
    }
}