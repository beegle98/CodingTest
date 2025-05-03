import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String s;
        while((s = br.readLine()) != null){
            for(int i=0;i<s.length();i++){
                char c = s.charAt(i);
                if(c=='i') sb.append('e');
                else if(c=='e') sb.append('i');
                else if(c=='I') sb.append('E');
                else if(c=='E') sb.append('I');
                else sb.append(c);
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}