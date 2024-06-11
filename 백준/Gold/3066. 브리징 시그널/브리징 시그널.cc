#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

vi LIS,arr;

int main(){
    FASTIO
    int tc; cin >> tc;
    for (int t = 0; t < tc; t++){
        int n;cin >> n;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            arr.push_back(x);
        }
        LIS.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++){
            if (LIS.back() < arr[i])
            {
                LIS.push_back(arr[i]);
            }
            else
            {
                int itr = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
                LIS[itr] = arr[i];
            }
        }
        cout << LIS.size() << '\n';
        LIS.clear();
        arr.clear();
    }
    return 0;
}
