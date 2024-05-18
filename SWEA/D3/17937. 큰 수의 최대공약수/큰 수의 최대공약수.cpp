#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);


int main(){
    FASTIO

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        string a,b; cin >> a >> b;
        cout << "#" << t << ' ';
        if(a==b) cout << a << '\n';
        else cout << "1\n";
    }
    return 0;
}
