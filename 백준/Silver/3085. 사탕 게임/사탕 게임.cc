#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int n;
string s[50];

void swap(int i,int j,int a,int b){
    char tmp = s[i][j];
    s[i][j]=s[i+a][j+b];
    s[i+a][j+b]=tmp;
}
int rowCnt(int i){
    int cnt=1, res=0;
    for(int j=1;j<n;j++){
        if(s[i][j-1]==s[i][j]) cnt++;
        else cnt=1;
        res = max(res,cnt);
    }
    return res;
}
int colCnt(int j){
    int cnt=1, res=0;
    for(int i=1;i<n;i++){
        if(s[i-1][j]==s[i][j]) cnt++;
        else cnt=1;
        res = max(res,cnt);
    }
    return res;
}
int solve(int i,int j){
    int res=0;
    if(i<n-1){
        swap(i,j,1,0);
        res = max(res,rowCnt(i));
        res = max(res,rowCnt(i+1));
        res = max(res,colCnt(j));
        swap(i,j,1,0);
    }
    if(j<n-1){
        swap(i,j,0,1);
        res = max(res,rowCnt(i));
        res = max(res,colCnt(j));
        res = max(res,colCnt(j+1));
        swap(i,j,0,1);
    }
    return res;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    int ans = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int ret = solve(i,j);
            ans = max(ans,ret);
            //cout << i << ":" << j << " " << ret << '\n';
        }
    }
    cout << ans;
    return 0;
}