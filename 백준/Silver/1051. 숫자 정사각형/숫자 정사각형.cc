#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int n,m,Max=1; 
char s[100][100];

void sol(int x,int y,int k){
    if(x+k>n-1 || y+k>m-1) return;
    char c=s[x][y];
    if(s[x+k][y]==c && s[x][y+k]==c && s[x+k][y+k]==c){
        Max = max(Max, k+1);
    }
    sol(x,y,k+1);
}

int main(){
    FASTIO
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sol(i,j,1);
        }
    }
    cout << Max*Max;
}