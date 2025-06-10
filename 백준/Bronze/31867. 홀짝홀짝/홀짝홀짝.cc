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
    string s; cin >> s;
    int sum=0;
    for(int i=0;i<n;i++){
        int x = s[i]-'0';
        if(x&1)sum++;
    }
    if(n-sum > sum) cout << "0";
    else if(n-sum < sum) cout << "1";
    else cout << "-1";
    return 0;
}