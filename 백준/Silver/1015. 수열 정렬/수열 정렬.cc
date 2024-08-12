#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;



int main(){
    FASTIO
    int n; cin >> n;
    int ans[100];
    vector<pi> arr;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        arr.push_back({x,i});
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int index = arr[i].second;
        ans[index] = i;
    }
    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    return 0;
}
