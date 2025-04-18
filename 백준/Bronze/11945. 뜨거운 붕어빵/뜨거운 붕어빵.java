import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        String[] str = new String[n];
        for(int i=0;i<n;i++){
            str[i] = br.readLine();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                System.out.print(str[i].charAt(m-1-j));
            }
            System.out.println();
        }
    }
}