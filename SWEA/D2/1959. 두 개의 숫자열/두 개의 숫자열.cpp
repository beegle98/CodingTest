#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const int MAX = 22;


int main()
{
    int tc; cin >> tc;
    for(int t=1;t<=tc;t++){
        int a[30],b[30],n,m; cin >> n >> m;
        if(n>m){
            swap(n,m);
            for(int i=0;i<m;i++) cin >> b[i];
            for(int i=0;i<n;i++) cin >> a[i];
        }
        else{
            for(int i=0;i<n;i++) cin >> a[i];
            for(int i=0;i<m;i++) cin >> b[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans += a[i]*b[i];
        }
        for(int i=1;i<=m-n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=a[j]*b[i+j];
            }
            ans = max(sum,ans);
        }
        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}