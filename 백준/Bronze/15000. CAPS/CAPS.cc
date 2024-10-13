#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


int main(){
    string s; cin >> s;
    for(int i=0;i<s.size();i++){
        s[i] = toupper(s[i]);
    }
    cout << s;

    return 0;
}

