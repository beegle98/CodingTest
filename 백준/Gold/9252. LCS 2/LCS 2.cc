#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

const int MAX = 1001;
string s1,s2;
int lcs[MAX][MAX];
void f(int x,int y){
    if(lcs[x][y]==0) return;
    if(lcs[x][y]==lcs[x][y-1]) f(x,y-1);
    else if(lcs[x][y]==lcs[x-1][y]) f(x-1,y);
    else{
        f(x-1,y-1);
        cout << s1[x-1];
    }
}
int main(){
    FASTIO
    cin >> s1 >> s2;
    int n,m;
    n=s1.size();
    m=s2.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s1[i]==s2[j]){
                lcs[i+1][j+1]=lcs[i][j]+1;
            }
            else{
                lcs[i+1][j+1]=max(lcs[i][j+1],lcs[i+1][j]);
            }
        }
    }
    cout << lcs[n][m] << '\n';
    f(n,m);
    return 0;
}