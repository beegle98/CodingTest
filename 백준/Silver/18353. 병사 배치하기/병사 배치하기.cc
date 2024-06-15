#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int n;
vi LIS,arr;

int main(){
    FASTIO
    cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    LIS.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(LIS.back()>arr[i]){
            LIS.push_back(arr[i]);
        }
        else{
            int itr = lower_bound(LIS.begin(),LIS.end(),arr[i],greater<int>())-LIS.begin();
            LIS[itr] = arr[i];
        }
    }
    cout << arr.size() - LIS.size();
    return 0;
}
