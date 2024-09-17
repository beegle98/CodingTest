#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
  
const int MAX = 2002;
int d[MAX][MAX],B[MAX][MAX],W[MAX][MAX];
int sumB[MAX][MAX],sumW[MAX][MAX];

int main(){
    FASTIO
    int n,m,k,Min=200000000;
    cin >> n >> m >> k;

    vector<string> s;
    

    for(int i=0;i<n;i++){
        string str; cin >> str;
        s.push_back(str);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            B[i][j]=(i+j+1)%2;
            if(s[i-1][j-1]=='B') d[i][j]=1;
            else d[i][j]=0;

            if(d[i][j]==B[i][j]){
                B[i][j]=0;
                W[i][j]=1;
            }
            else{
                B[i][j]=1;
                W[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sumB[i][j]=sumB[i-1][j]+sumB[i][j-1]-sumB[i-1][j-1]+B[i][j];
            sumW[i][j]=sumW[i-1][j]+sumW[i][j-1]-sumW[i-1][j-1]+W[i][j];
        }
    }
    for(int i=0;i<=n-k;i++){
        for(int j=0;j<=m-k;j++){
            int tmp;
            tmp = sumB[i+k][j+k]-sumB[i][j+k]-sumB[i+k][j]+sumB[i][j];
            if(tmp < Min) Min = tmp;
            tmp = sumW[i+k][j+k]-sumW[i][j+k]-sumW[i+k][j]+sumW[i][j];
            if(tmp < Min) Min = tmp;
        }
    }
    cout << Min;
    return 0;
}