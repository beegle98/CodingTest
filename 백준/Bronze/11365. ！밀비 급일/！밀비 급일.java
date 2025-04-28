import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String s = br.readLine();
            if(s.equals("END")) break;
            int n = s.length();
            for(int i=0;i<n;i++){
                System.out.print(s.charAt(n-i-1));
            }
            System.out.println();
        }
    }
}