#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

bool visited[11][11];

bool check(int x1, int y1, int x2, int y2){
    if((abs(x1-x2)==2 && abs(y1-y2)==1)
    ||(abs(x1-x2)==1 && abs(y1-y2)==2)){
        return 1;
    }
    return 0;
}

int main()
{
    FASTIO
    int n = 36,ans=1;
    string s[50];
    for(int i=0;i<n;i++) cin >> s[i];
    visited[s[0][0]-'A'][s[0][1]-'0']=1;
    for(int i=1;i<n;i++){

        int a = s[i-1][0]-'A';
        int b = s[i-1][1]-'0';
        int x = s[i][0]-'A';
        int y = s[i][1]-'0';
        
        if(!check(a,b,x,y) || visited[x][y]){
           ans=0;
           break;
        }
        visited[x][y]=1;
    }
    if(!check(s[0][0]-'A',s[0][1]-'0',s[35][0]-'A',s[35][1]-'0')) ans =0;
    if(ans) cout << "Valid\n";
    else cout << "Invalid\n";
    return 0;
}