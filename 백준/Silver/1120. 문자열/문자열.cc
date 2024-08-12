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
    int Min=10000;
    string a,b; cin >> a >> b;
    for(int i=0;i<=b.size()-a.size();i++){
        int cnt;
        cnt=0;
        for(int j=i;j<i+a.size();j++){
            if(a[j-i]!=b[j]) cnt++;
        }
        Min = min(cnt,Min);
    }
    cout << Min;
}