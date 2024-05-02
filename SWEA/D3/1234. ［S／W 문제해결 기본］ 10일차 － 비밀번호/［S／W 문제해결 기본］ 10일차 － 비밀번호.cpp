
#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int s[1111];
 
int main(){
    FASTIO
 
    int ans,T=10;
    for(int t=1;t<=T;t++){
        int n; cin >> n;
        string s; cin >> s;
        for(int i=0;i<s.size();i++){
            if(s[i]==s[i+1]){
                s.erase(i,2);
                i-=2;
                if(i<-1) i=-1;
            }
        }
        cout << "#" << t << ' ' << s << '\n';
    }
    return 0;
}