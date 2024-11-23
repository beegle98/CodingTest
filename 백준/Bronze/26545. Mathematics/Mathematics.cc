#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;

int main(){
    int n, sum=0; cin >> n;

    for(int i=0;i<n;i++){
        int x; cin >> x;
        sum += x;
    }
    cout << sum;
    return 0;
}