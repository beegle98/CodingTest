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
    
    int T; cin >> T;
    for(int t=0;t<T;t++){
        int n; cin >> n;
        vector<pi> s;
        for(int i=0;i<n;i++){
            int x, y; cin >> x >> y;
            s.push_back({x,y});
        }
        sort(s.begin(),s.end());
        int Min=s[0].second;
        for(int i=1;i<s.size();i++){
            if(s[i].second>Min){
                s[i].second=0;
            }
            else Min = s[i].second;
        }
        int sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i].second) sum++;
        }
        cout << sum << '\n';
    }
    
    return 0;
}