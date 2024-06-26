#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int n,b,arr[30],Min;

void f(int k,int sum){
    if(k==n){
        if(sum>=b){
            Min = min(Min,sum);
        }
        return;
    }
    f(k+1,sum+arr[k]);
    f(k+1,sum);
}

int main()
{
    int tc; cin >> tc;
    for(int t=1;t<=tc;t++){
        cin >> n >> b;
        for(int i=0;i<n;i++) cin >> arr[i];
        Min = 100000000;
        f(0,0);
        cout << "#" << t << ' ' << Min-b << '\n';
    }
    return 0;
}