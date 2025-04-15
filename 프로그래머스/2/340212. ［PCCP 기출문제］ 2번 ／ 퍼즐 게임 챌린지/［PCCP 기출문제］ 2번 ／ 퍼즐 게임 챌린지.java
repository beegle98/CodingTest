import java.io.*;
import java.util.*;
class Solution {
    public int solution(int[] diff, int[] time, long limit) {
        int ans = 0;
        int l=1, r=100000;
        while(l<r){
            int mid = (l+r)/2;
            //System.out.println("mid:"+mid);
            if(check(mid, diff, time, limit)){
                r=mid;
            }else{
                l=mid+1;
            }
            
        }
        ans = r;
        return ans;
    }
    private boolean check(int lev, int[] d, int[] t, long limit){
        long sum=0;
        for(int i=0;i<t.length;i++){
            if(d[i]<=lev) sum += t[i];
            else sum += t[i] + (long)(d[i]-lev)*(t[i-1]+t[i]);
            if(sum>limit) return false;
        }
        return true;
    }
}