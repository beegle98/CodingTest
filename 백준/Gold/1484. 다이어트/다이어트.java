import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int G = Integer.parseInt(st.nextToken());
        List<Long> list = new ArrayList<>();
        for(long i=1;;i++){
            if(i*i-(i-1)*(i-1)>100_000) break;
            list.add(i*i);
        }
        int l=0,r=1;
        List<Long> ans = new ArrayList<>();
        while(r<list.size()){
            Long a = list.get(l);
            Long b = list.get(r);
            if(b-a==G){
                ans.add((long)Math.sqrt(b));
                r++;
            }
            else if(b-a>G) l++;
            else r++;
        }
        if (ans.isEmpty()) {
            System.out.println("-1");
        }else{
            for(int i=0;i<ans.size();i++){
                System.out.println(ans.get(i));
            }
        }
    }
}