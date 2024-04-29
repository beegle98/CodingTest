#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

const int N = 100;
int s[N][N];
 
int main(){
    FASTIO
 
    int ans,T=10;
    int sumX[N],sumY[N],sumC[2];
    
    for(int t=1;t<=T;t++){
        int tc; cin >> tc;
        ll Max = -3000000000;
        for(int i=0;i<N;i++){
            sumX[i]=0;
            sumY[i]=0;
            for(int j=0;j<N;j++){
                cin >> s[i][j];
                sumX[i]+=s[i][j];
            }
            if(sumX[i]>Max) Max = sumX[i];
        }
        sumC[0]=0;
        sumC[1]=0;
        for(int i=0;i<N;i++){
            sumC[0]+=s[i][i];
            sumC[1]+=s[i][N-1-i];
            for(int j=0;j<N;j++){
                sumY[i]+=s[j][i];
            }
            if(sumY[i]>Max) Max = sumY[i];
        }
        for(int i=0;i<2;i++){
            if(sumC[i]>Max) Max = sumC[i];
        }
        ans = Max;
        cout << "#" << tc << ' ' << ans << '\n';
    }
    return 0;
}