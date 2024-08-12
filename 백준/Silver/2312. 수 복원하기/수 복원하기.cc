#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const int N = 100000;
int arr[N];

int main()
{
    FASTIO
    int n; cin >> n;

    arr[1]=1;

    for(int i=2;i*i<=N;i++){
        if(arr[i]) continue;
        for(int j=i*2;j<=n;j+=i){
            arr[i]=1;
        }
    }
    for(int i=0;i<n;i++){
        int k,cnt; cin >> k;
        for(int j=2;j<=k;j++){
            cnt=0;
            while(k%j==0){
                cnt++;
                k/=j;
            }
            if(cnt){
                cout << j << ' ' << cnt << '\n';
            }
            if(k<=1) break;
        }
    }
    return 0;

}


