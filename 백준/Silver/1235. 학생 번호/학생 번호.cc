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
    FASTIO
    int n; cin >> n;
    string s[1001];
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    int key=0,len=s[0].size();
    for(int k=len-1;k>=0;k--){
        key=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s[i].substr(k)==s[j].substr(k)){
                    key=1;
                    break;
                }
            }
            if(key) break;
        }
        if(!key){
            cout << len-k;
            break;
        }
    }
    return 0;
}
