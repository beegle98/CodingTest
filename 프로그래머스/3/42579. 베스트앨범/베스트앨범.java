import java.util.*;
import java.lang.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        ArrayList<Integer> ans = new ArrayList<>();
        
        HashMap<String, Integer> sum = new HashMap<>();
        HashMap<String, HashMap<Integer, Integer>> music = new HashMap<>();
        
        for(int i=0;i<genres.length;i++){
            if(!sum.containsKey(genres[i])){
                HashMap<Integer, Integer> tmp = new HashMap<>();
                tmp.put(i,plays[i]);
                music.put(genres[i],tmp);
                sum.put(genres[i],plays[i]);
            }else{
                sum.put(genres[i], sum.get(genres[i]) + plays[i]);
                music.get(genres[i]).put(i,plays[i]);
            }
        }
        List<String> keySet = new ArrayList(sum.keySet());
        
        Collections.sort(keySet, (s1, s2) -> sum.get(s2)-sum.get(s1));
        
        for(String key : keySet){
            HashMap<Integer, Integer> map = music.get(key);
            List<Integer> genre_key = new ArrayList(map.keySet());
            
            Collections.sort(genre_key, (s1,s2) -> (map.get(s2)-map.get(s1)));
            
            for(int i=0;i<Math.min(2,genre_key.size());i++) ans.add(genre_key.get(i));
        }
        return ans.stream().mapToInt(i -> i).toArray();
        
    }
}