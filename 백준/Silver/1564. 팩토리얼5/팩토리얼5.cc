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
    int n; cin >> n;
    ll sum=1;
    ll MOD = 1e12;
    for(int i=1;i<=n;i++){
        sum = sum*i;
        while(sum%10==0){
            sum/=10;
        }
        sum%=MOD;
    }
    printf("%05d\n",sum%100000);
    return 0;
}