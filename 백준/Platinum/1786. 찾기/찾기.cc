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
vi kmp(string s, string p){
    vi ans;
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j =0;
    for(int i = 0 ; i < n ; i++){
        while(j>0 && s[i] != p[j])
            j = pi[j-1];
        if(s[i] == p[j]){
            if(j==m-1){
                ans.push_back(i-m+1);
                j = pi[j];
            }else{
                j++;
            }
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string s, p;
    getline(cin, s);
    getline(cin, p);
    auto matched = kmp(s,p);
    printf("%d\n", (int)matched.size());
    for(auto i : matched)
        printf("%d ", i+1);

    
    return 0;
}

