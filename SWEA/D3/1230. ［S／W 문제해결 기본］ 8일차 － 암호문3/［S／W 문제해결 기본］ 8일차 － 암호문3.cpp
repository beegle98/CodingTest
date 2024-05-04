#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;


vector<string> str;

int main(){
    FASTIO
 
    int ans,T=10;
    for(int t=1;t<=T;t++){
        str.clear();
        int n,m; cin >> n;
        for(int i=0;i<n;i++){
            string x; cin >> x;
            str.push_back(x);
        }
        cin >> m;
        for(int i=0;i<m;i++){
            char c;
            int x,y;
            cin >> c;
            if(c=='I'){
                cin >> x >> y;
                for(int j=0;j<y;j++){
                    string s; cin >> s;
                    str.insert(str.begin()+x+j,s);
                }
            }
            else if(c=='D'){
                cin >> x >> y;
                for(int j=0;j<y;j++){
                    str.erase(str.begin()+x);
                }
                
            }
            else if(c=='A'){
                cin >> y;
                for(int j=0;j<y;j++){
                    string s; cin >> s;
                    str.push_back(s);
                }
            }
        }
        cout << "#" << t << ' ';
        int len=10;
        if(str.size()<10) len=str.size();
        for(int i=0;i<len;i++){
            cout << str[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}