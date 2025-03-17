import java.util.*;
import java.io.*;

public class Main {
    static int n, k, ans=0;
    static List<Integer>[] child = new ArrayList[50];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) child[i] = new ArrayList<>();
        List<Integer> start = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<n;i++){
            int x = Integer.parseInt(st.nextToken());
            list.add(x);
        }
        k = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++) {
            if(i==k) continue;
            if(list.get(i)==-1) start.add(i);
            else child[list.get(i)].add(i);
        }
        for(int i=0;i<start.size();i++){
            dfs(start.get(i));
        }
        System.out.println(ans);
    }
    static void dfs(int x) {
        if(child[x].isEmpty()) ans++;
        for(int i=0;i<child[x].size();i++){
            dfs(child[x].get(i));
        }
    }

}
