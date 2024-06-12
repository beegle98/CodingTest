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
    int L,n; cin >> L;
    vi s;
    s.push_back(0);
    for(int i=0;i<L;i++){
        int x; cin >> x;
        s.push_back(x);
    }
    cin >> n;
    sort(s.begin(),s.end());
    int sum=0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]<n && s[i+1]>n){
            sum = (n-s[i]-1) * (s[i+1]-n-1) + s[i+1]-s[i]-2;
            break;
        }
    }
    cout << sum;
    return 0;
}
