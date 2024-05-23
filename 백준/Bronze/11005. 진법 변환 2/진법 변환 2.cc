#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int n,k;
void print(int n){
    char c;
    if(n>=10){
        c='A'+n-10; cout << c;
    }
    else cout << n;
}
void f(int n){
    if(n<k){
        print(n);
        return;
    }
    f(n/k);
    print(n%k);
}


int main(){
    FASTIO
    cin >> n >> k;
    f(n);
    return 0;
}
