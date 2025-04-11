#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
	int a,b; cin >> a >> b;
    if(a>=3 && b<=4) cout << "TroyMartian\n";
    if(a<=6 && b>=2) cout << "VladSaturnian\n";
    if(a<=2 && b<=3) cout << "GraemeMercurian\n";
    return 0;
}