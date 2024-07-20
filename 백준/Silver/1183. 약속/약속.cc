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
    int n; cin >> n;
    vi s;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        s.push_back(b-a);
    }
    sort(s.begin(),s.end());

    if(s.size()%2==0){
        cout << s[n/2]-s[n/2-1]+1  <<'\n';
    }
    else{
        cout << "1\n";
    }

    return 0;

}


