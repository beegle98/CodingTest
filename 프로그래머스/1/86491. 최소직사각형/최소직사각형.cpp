#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
    int ans = 1e9;
    int n = arr.size();
    for(int i=1;i<=1000;i++){
        int Max=0,key=1;
        for(int j=0;j<n;j++){
            if(arr[j][0] > i && arr[j][1] > i){
                key=0;
                break;
            }
            else if(arr[j][0] <= i && arr[j][1] <=i){
                Max = max(Max, min(arr[j][0],arr[j][1]));
            }
            else{
                Max = max(Max, max(arr[j][0],arr[j][1]));
            }
            
        }
        if(key) ans = min(ans, Max*i);
    }
    return ans;
}