#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int main()
{
    FASTIO
    int ans[100],arr[100],n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        ans[i]=0;
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(ans[j]) continue;
            if(cnt==arr[i]){
                ans[j]=i+1;
                break;
            }
            cnt++;
        }
    }
    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    return 0;
}
