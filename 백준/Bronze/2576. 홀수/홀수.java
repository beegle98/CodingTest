import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = 7;
        int sum=0, min=1000;
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(br.readLine());
            if(x%2==1){
                sum+=x;
                min=Math.min(min,x);
            }
        }
        if (sum == 0) {
            System.out.println("-1");
        }else{
            System.out.println(sum);
            System.out.println(min);
        }
    }
}
