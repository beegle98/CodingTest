import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while(true){
            String s = br.readLine();
            if(s.equals("END")) break;
            StringBuilder tmp = new StringBuilder(s);
            sb.append(tmp.reverse()+"\n");
        }
        System.out.println(sb);
    }
}