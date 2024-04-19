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
 
    int ans,x,y;
     
    for(int t=1;t<=10;t++){
        int test_case;
        cin >> test_case;
        for(int i=0;i<N;i++){
            memset(s[i],0,sizeof(int)*N);
        }
 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> s[i][j];
                if(s[i][j]==2){
                    x=i;
                    y=j;
                }
            }
        }
        while(x>0){
            if(y>0 && s[x][y-1]==1){
                while(y>0 && s[x][y-1]==1) y-=1;
            }
            else if(y<N-1 && s[x][y+1]==1){
                while(y<N-1 && s[x][y+1]==1) y+=1;
            }
            x--;
        }
        cout << "#" << test_case << ' ' << y << '\n';
    }
    return 0;
}
