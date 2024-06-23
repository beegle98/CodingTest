#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main()
{
    FASTIO
    string s;
    int sum;
    while(1){
        getline(cin,s);
        if(s=="#") break;
        sum = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
            s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                sum++;
            }
        }
        cout << sum << '\n';
    }
    
    return 0;
}