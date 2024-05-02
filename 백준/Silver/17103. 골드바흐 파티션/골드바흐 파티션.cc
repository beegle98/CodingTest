#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int chk[1000001];
vi p;
int main(){
    FASTIO

    int T; cin >> T;

    for(int i=2;i*i<=1000000;i++){
        if(chk[i]) continue;
        for(int j=i*2;j<=1000000;j+=i){
            chk[j]=1;
        }
    }
    for(int i=2;i<=1000000;i++){
        if(!chk[i]) p.push_back(i);
    }
    for(int i=0;i<T;i++){
        int x; cin >> x;
        int sum=0,l=0,r=p.size()-1;
        while(l<=r){
            if(p[l]+p[r]==x){
                sum++;
                l++;
                r--;
            }
            else if(p[l]+p[r]>x){
                r--;
            }
            else l++;
        }
        cout << sum << '\n';
    }
    return 0;
}