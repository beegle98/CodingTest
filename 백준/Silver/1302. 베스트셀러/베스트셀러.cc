#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

map<string,int> book;

int main()
{
    FASTIO
    int n; cin >> n;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        book[s]++;
    }
    string ans;
    int MAX=0;
    for(auto i=book.begin();i!=book.end();i++){
        if(MAX < i->second){
            MAX = i->second;
            ans = i->first;
        }
    }
    cout << ans;
    return 0;
}
