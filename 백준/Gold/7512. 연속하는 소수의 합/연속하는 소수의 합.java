import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        final int MAX = (int)1e7;
        int T = Integer.parseInt(st.nextToken());
        boolean[] prime = new boolean[MAX];
        List<Integer> pList = new ArrayList<>();
        int[] cnt = new int[MAX];
        for(int i=2;i<=(int)Math.sqrt(MAX);i++){
            if(prime[i]) continue;
            for(int j=i*2;j<MAX;j+=i){
                prime[j] = true;
            }
        }
        for(int i=2;i<MAX;i++){
            if(!prime[i]) pList.add(i);
        }
        for(int t=1;t<=T;t++){
            int ans = 0;
            int m = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            Arrays.fill(cnt,0);
            for(int i = 0; i < m; i++){
                int n = Integer.parseInt(st.nextToken());
                int sum = 0;
                for(int j=0;j<n;j++){
                    sum += pList.get(j);
                }
                if(!prime[sum]) ans = Math.min(ans,sum);
                for(int j=n;j<=pList.size();j++){
                    sum+=pList.get(j)-pList.get(j-n);
                    if(sum>=MAX) break;
                    if(!prime[sum]) cnt[sum]++;
                }
            }
            for(int i=0;i<MAX;i++){
                if(cnt[i]==m){
                    ans = i;
                    break;
                }
            }
            sb.append("Scenario ").append(t).append(":\n").append(ans).append("\n\n");
        }
        System.out.println(sb);
    }
}