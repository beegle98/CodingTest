class Solution {
    public int solution(int[] band, int health, int[][] at) { 
        int t = band[0];
        int x = band[1];
        int y = band[2];
        int n = at.length;
        int end = at[n-1][0];
        int max_h = health;
        int h = max_h;
        int idx=0, s=0;
        for(int i=1;i<=end;i++){
            if(at[idx][0]==i){
                h-=at[idx][1];
                idx++;
                s=0;
            }else{
                s++;
                if(s==t){
                    h+=y;
                    s=0;
                }
                h+=x;
                h = Math.min(h,max_h);
            }
            if(h<=0){
                h=-1;
                break;
            }
        }
        return h;
    }
}