import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        List<Integer> arr = new LinkedList<>();
        List<Integer> ans = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(st.nextToken());
            arr.add(x);
        }
        int s = Integer.parseInt(br.readLine());
        while(s>0 && !arr.isEmpty()){
            int max=0, idx=0;
            for(int i=0;i<Math.min(s+1,arr.size());i++){
                if(max<arr.get(i)){
                    max=arr.get(i);
                    idx=i;
                }
            }
            s -= idx;
            ans.add(arr.get(idx));
            arr.remove(idx);
        }
        while(!arr.isEmpty()){
            ans.add(arr.get(0));
            arr.remove(0);
        }
        for(int i=0;i<ans.size();i++){
            System.out.print(ans.get(i) + " ");
        }
    }


}
