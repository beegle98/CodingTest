#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()



int main()
{
    FASTIO
    int n,ans=0; cin >> n;
    stack <int> st;
    for(int i=0; i<n; i++){
        int x,y;cin >> x >> y;
        while(!st.empty()&&st.top()>=y){
            if(st.top()!=y) ans++;
            st.pop();
        }
        st.push(y);
    }
    while(!st.empty()){
        if(st.top()!=0) ans++;
        st.pop();
    }
    cout << ans;
    return 0;
}
