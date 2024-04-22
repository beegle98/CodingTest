#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

const int MAX = 4000400;
int pn[MAX];
vi s;
 
int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

    int n; cin >> n;
    if(n==1){
        cout << '0';
        return 0;
    }
    pn[1]=1;
    for(int i=2;i*i<=n;i++){
        if(pn[i]) continue;
        for(int j=i*2;j<=n;j+=i){
            pn[j]=1;
        }
    }
    for(int i=n;i>1;i--){
        if(!pn[i]) s.push_back(i);
    }
    int sum=0,tmp=0;
    if(s[0]==n) sum++;
    for(int i=0;i<s.size();i++){
        tmp=s[i];
        for(int j=i+1;j<s.size();j++){
            tmp+=s[j];
            if(tmp>n) break;
            else if(tmp==n) sum++;
        }
    }
    cout << sum;
    return 0;
}