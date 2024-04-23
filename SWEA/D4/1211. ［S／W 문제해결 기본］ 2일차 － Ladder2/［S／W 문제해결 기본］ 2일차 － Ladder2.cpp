#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

const int N = 100;
int s[N+1][N+1];
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int ans;
     
    for(int t=1;t<=10;t++){
        int test_case;
        cin >> test_case;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> s[i][j];
            }
        }
        int x, y, sum, Min=100000000;
        for(int i=0;i<N;i++){
            sum=0;
            if(!s[0][i]) continue;
            x=0;
            y=i;
            while(x<N){
                if(y>0 && s[x][y-1]==1){
                    while(y>0 && s[x][y-1]==1){
                        y-=1;
                        sum++;
                    }
                }
                else if(y<N-1 && s[x][y+1]==1){
                    while(y<N-1 && s[x][y+1]==1){
                        y+=1;
                        sum++;
                    }
                }
                x++;
                sum++;
            }
            if(Min>=sum){
                Min = sum;
                ans = i;
            }
        }
        
        cout << "#" << test_case << ' ' << ans << '\n';
    }
    return 0;
}