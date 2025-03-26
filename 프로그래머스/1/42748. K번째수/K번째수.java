import java.util.*;
import java.lang.*;
import java.io.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        List<Integer> ans = new ArrayList<>();
        List<Integer> arr = new ArrayList<>();
        for(int i=0;i<array.length;i++) arr.add(array[i]);
        for(int i=0;i<commands.length;i++){
            int a = commands[i][0];
            int b = commands[i][1];
            int k = commands[i][2];
            List<Integer> sub = new ArrayList<>(arr.subList(a-1,b));
            Collections.sort(sub);
            ans.add(sub.get(k-1));
        }
        return ans.stream().mapToInt(i->i).toArray();
    }
}