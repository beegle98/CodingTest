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
    int n,m,ans=-1;
    cin >> n >> m;
    for(int i=m;i<=100;i++){
        if(i%2==0){
            int k=i*(i-1)/2;
            if(n>=k && (n-k)%i==0){
                int r=(n-k)/i;
                for(int j=0;j<i;j++){
                    cout << r+j << ' ';
                }
                return 0;
            }
        }
        else{
            int k=n/i-(i-1)/2;
            if(n%i==0 && k>=0){
                for(int j=0;j<i;j++){
                    cout << k+j << ' ';
                }
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
