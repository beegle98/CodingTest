#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int n,ans[1001001];
vector<pi> arr;
vi LIS;
vi record;/** LIS배열에 몇번째 인덱스에 들어가는지 기록*/

int main(){
    FASTIO
    cin >> n;
    for(int i=0;i<n;i++){
        int x, y; cin >> x >> y;
        arr.push_back({x,y});
    }
    sort(arr.begin(), arr.end());
    LIS.push_back(arr[0].second);
    record.push_back(1);
    for(int i=1;i<arr.size();i++){
        if(LIS.back()<arr[i].second){
            LIS.push_back(arr[i].second);
            record.push_back(LIS.size());
        }
        else{
            int itr = lower_bound(LIS.begin(),LIS.end(),arr[i].second) - LIS.begin();
            LIS[itr] = arr[i].second;
            record.push_back(itr+1);
        }
    }
    int k=LIS.size();
    for(int i=record.size()-1;i>=0;i--){
        if(record[i]==k){
            ans[i]=1; //LIS에 속하는 인덱스 체크
            k--;
        }
    }
    cout << n-LIS.size() << '\n';
    for(int i=0;i<n;i++){
        if(!ans[i]) cout << arr[i].first << ' ';
    }
    return 0;
}
