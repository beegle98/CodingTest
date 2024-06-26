#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const int MAX = 20;
int n,m,arr[MAX][MAX];

int sumc(int x,int y){
    int sum=0;
    for(int i=-(m-1);i<m;i++){
        if(x+i>=0 && x+i <n) sum += arr[x+i][y];
    }
    for(int j=-(m-1);j<m;j++){
        if(y+j>=0 && y+j <n) sum += arr[x][y+j];
    }
    sum-=arr[x][y];
    return sum;
}  
int sumx(int x,int y){
    int sum=0;
    for(int i=-m+1;i<m;i++){
        if(x+i>=0 && x+i <n && y+i>=0 && y+i<n) sum+=arr[x+i][y+i];
        if(x+i>=0 && x+i <n && y-i>=0 && y-i<n) sum+=arr[x+i][y-i];
    }
    sum-=arr[x][y];
    return sum;
}
int main()
{
    int tc; cin >> tc;
    for(int t=1;t<=tc;t++){
        cin >> n >> m; 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> arr[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum = max(sumc(i,j),sumx(i,j));;
                ans = max(ans, sum);
            }
        }
        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}