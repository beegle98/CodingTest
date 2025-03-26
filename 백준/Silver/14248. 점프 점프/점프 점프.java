import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {

    static int n,s;
    static int[] arr = new int[100011];
    static boolean[] visited = new boolean[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=1;i<=n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        s = Integer.parseInt(br.readLine());
        solve(s);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(visited[i]) ans++;
        }
        System.out.println(ans);
    }

    static void solve(int x){
        if(x<1 || x>n || visited[x]) return;
        visited[x] = true;
        solve(x-arr[x]);
        solve(x+arr[x]);
    }
}