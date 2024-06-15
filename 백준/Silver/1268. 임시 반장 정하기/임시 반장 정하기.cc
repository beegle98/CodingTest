#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int arr[1111][6], sum[1111];
bool check[1111][1111];


int main()
{
    FASTIO
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin >> arr[i][j];
        }
    }
    for(int t=1;t<=5;t++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(arr[i][t]==arr[j][t] && !check[i][j]){
                    check[i][j] = check[j][i] = 1;
                    sum[i]++;
                    sum[j]++;
                }
            }
        }
    }
    int ans=1, MAX=-1;
    for(int i=1;i<=n;i++){
        if(MAX < sum[i]){
            MAX = sum[i];
            ans = i;
        }
    }
    cout << ans;
    return 0;
}
