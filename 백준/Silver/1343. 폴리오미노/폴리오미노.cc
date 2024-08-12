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
    string s,ans; cin >> s;
    int n = s.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='.'){
            if(cnt%2) break;
            for(int j=0;j<cnt/4;j++) ans.append("AAAA");
            for(int j=0;j<cnt%4/2;j++) ans.append("BB");
            ans.append(".");
            cnt=0;
        }
        else cnt++;
    }
    if(cnt==0){
        cout << ans;
    }
    else{
        if(cnt%2) cout << "-1\n";
        else{
            for(int i=0;i<cnt/4;i++) ans.append("AAAA");
            for(int i=0;i<cnt%4/2;i++) ans.append("BB");
            cout << ans;
        }
    }
    return 0;
}