import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N,d,k,c;
        N = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        
        int[] list = new int[N];
        for(int i=0;i<N;i++) list[i]=Integer.parseInt(br.readLine());
        int[] selected = new int[d+1];
        int cnt=0, ans=0, bonus=0;
        for(int i=0;i<k;i++) {
        	if(++selected[list[i]]==1) cnt++;
        }
        bonus = selected[c] == 0 ? 1 : 0;
        ans = cnt + bonus;
        for(int i=k;i<N+k;i++) {
        	if(--selected[list[i-k]]==0) cnt--;
        	if(++selected[list[i%N]]==1) cnt++;
        	bonus = selected[c] == 0 ? 1 : 0;
        	ans = Math.max(ans, cnt+bonus);
        }
        System.out.println(ans);
    }
    
}