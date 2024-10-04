#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pi;

int main(){
    FASTIO
    string s; cin >> s;
    for(int i=s.size()-1;i>=0;i--){
        cout<<s[i];
    }
    return 0;
}
