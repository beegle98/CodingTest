#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;

int main(){
    int s[8];
    char ans = 'S';
    for(int i=0;i<8;i++){
        cin>>s[i];
        ans = s[i]==9 ? 'F' : ans;
    }
    cout<<ans;
    return 0;
}

