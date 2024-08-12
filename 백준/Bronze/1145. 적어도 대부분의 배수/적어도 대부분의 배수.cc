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
    int cnt,s[5];
    for(int i=0;i<5;i++) cin >> s[i];

    for(int i=1;i<=2000000;i++){
        cnt=0;
        for(int j=0;j<5;j++){
            if(i%s[j]==0) cnt++;
        }
        if(cnt>=3){
            cout << i << '\n';
            break;
        }
    }
}