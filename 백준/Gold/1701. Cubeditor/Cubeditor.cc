#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


vi getPi(string p){
    int n = p.size(), j=0;
    vi pi(n);
    for(int i = 1; i< n ; i++){
        while(j > 0 && p[i] !=  p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

int main(){

    string p; cin >> p;
    int n = p.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        string subStr = p.substr(i,n-i);
        vi v = getPi(subStr);
        for(int j=0;j<v.size();j++) ans = max(ans, v[j]); 
    }
    cout << ans;
    return 0;
}

