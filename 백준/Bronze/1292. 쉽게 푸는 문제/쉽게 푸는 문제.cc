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
    int arr[1111],sum[1111],a,b;
    cin >> a >> b;
    sum[0]=0;
    int k=1,cnt=1;
    while(cnt<=1000){
        for(int i=0;i<k;i++){
            arr[cnt]=k;
            cnt++;
        }
        k++;
    }
    for(int i=1;i<=1000;i++){
        sum[i]=sum[i-1]+arr[i];
    }
    cout << sum[b] - sum[a-1]; 
}
