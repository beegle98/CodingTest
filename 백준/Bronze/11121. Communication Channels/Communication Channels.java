import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        while(n-->0){
            String[] str = br.readLine().split(" ");
            if (str[0].equals(str[1])) {
                System.out.println("OK");
            }else{
                System.out.println("ERROR");
            }
        }
    }
}