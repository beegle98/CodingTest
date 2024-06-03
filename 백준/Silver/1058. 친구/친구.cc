#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int n,Max=0,cnt[100];
char s[100][100];


int main(){
    FASTIO
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i) continue;
            if(s[i][j]=='Y'){
                cnt[i]++;
                for(int k=i+1;k<n;k++){
                    if(s[k][j]=='Y' && s[i][k]=='N'){
                        cnt[i]++;
                        cnt[k]++;
                        s[i][k]='O';
                        s[k][i]='O';
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        Max = max(Max,cnt[i]);
    }
    cout << Max;
}