import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {

    static int n,s;
    static int[] arr = new int[100011];
    static boolean[] visited = new boolean[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        for(int i=1;i<=n;i++){
            sb.append(i).append(". ").append(br.readLine()).append("\n");
        }
        System.out.println(sb);
    }

}