// 수 색칠하기
#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
  
const int MAX = 2002;

int main(){
    FASTIO
    int n,m,k,Min=200000000;
    cin >> n >> m >> k;

    vector<string> s;
    int d[MAX][MAX],sum[MAX][MAX];

    for(int i=0;i<n;i++){
        string str; cin >> str;
        s.push_back(str);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='B') d[i][j]=1;
            else if(s[i][j]=='W') d[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+d[i][j];
        }
    }
    for(int i=1;i<=n-k+1;i++){
        for(int j=1;j<=m-k+1;j++){
        }
    }
    return 0;
}