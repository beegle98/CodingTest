#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
    FASTIO

    ll sum = 0;
    for(int i=0;i<5;i++){
        int x; cin >> x;
        sum += x;
    }
    cout << sum;
    return 0;
}