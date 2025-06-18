#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
	int n; cin >> n;
    int x=0,y=0;
    int ans=0;
    for(int i=0;i<n;i++){
        char c; cin >> c;
        if(ans) continue;
        if(c=='D') x++;
        else y++;
        if(abs(x-y)>=2) ans=1; 
    }
    cout << x << ":" << y;
    return 0;
}