#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
  
const int N = 1111;
ll sumA[N],sumB[N],t,ans=0;
map<int,int> sum;

int main(){
    FASTIO

    ll a[N],b[N];
    int n,m;

    cin >> t;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sumA[i]=sumA[i-1]+a[i];
    }
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> b[i];
        sumB[i]=sumB[i-1]+b[i];
    }

    for(int i=0;i<m;i++){
        for(int j=i+1;j<=m;j++){
            int tmp=sumB[j]-sumB[i];
            auto itr = sum.find(tmp);
            if(itr == sum.end()){
                sum[tmp]=1;
            }
            else sum[tmp]++;
        }
    }
    /*for(auto itr = sum.begin(); itr != sum.end(); itr++){
        cout << itr->first << ' ' << itr->second << '\n';
    }*/
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int tmp = sumA[j]-sumA[i];

            auto itr = sum.find(t-tmp);
            if(itr != sum.end()){
                ans += itr->second;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
