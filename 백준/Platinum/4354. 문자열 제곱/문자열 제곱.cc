#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


vi getPi(string p){
    int m = (int)p.size(), j=0;
    vi pi(m, 0);
    for(int i = 1; i< m ; i++){
        while(j > 0 && p[i] !=  p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int ans,n;
    string p;
    while(1){
        cin >> p;
        if(p[0]=='.') break;
        n=p.size();
        auto pi = getPi(p);
        if(n%(n-pi[n-1])) cout << 1 << '\n';
        else cout << n/(n-pi[n-1]) << '\n';
    }

    return 0;
}

