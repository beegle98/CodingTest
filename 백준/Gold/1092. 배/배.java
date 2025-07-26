import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        List<Integer> crane =  new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            crane.add(Integer.parseInt(st.nextToken()));
        }
        int m = Integer.parseInt(br.readLine());
        List<Integer> box = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<m;i++) {
            box.add(Integer.parseInt(st.nextToken()));
        }
        crane.sort(Collections.reverseOrder());
        box.sort(Collections.reverseOrder());
        int ans=0;
        if(crane.get(0)<box.get(0)){
            ans=-1;
        }
        else{
            while(!box.isEmpty()){
                for(int c : crane){
                    for(int i=0;i<box.size();i++){
                        if(c>=box.get(i)){
                            box.remove(i);
                            break;
                        }
                    }
                }
                ans++;
            }
        }
        System.out.println(ans);
    }
}