#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int arr[100][100];
bool visited[100][100];
int n,m;
vector<pi> v;

bool check(int x,int y){
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int nx = x+i;
            int ny = y+j;
            if(nx<0||ny<0||nx>=n||ny>=m||(i==0&&j==0)) continue;
            if(arr[x][y]<arr[nx][ny]) return false;
        }
    }
    return true;
}

void dfs(int x,int y){
    visited[x][y]=1;
    v.push_back({x,y});
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int nx = x+i;
            int ny = y+j;
            if(nx<0||ny<0||nx>=n||ny>=m||(i==0&&j==0)||visited[nx][ny]) continue;
            if(arr[x][y]==arr[nx][ny]){
                dfs(nx,ny);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
	cin >> n >> m; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j] || arr[i][j]==0) continue;
            dfs(i,j);
            int res=1;
            for(pi p : v){
                if(!check(p.first,p.second)){
                    res=0;
                    break;
                }
            }
            if(!res){
                for(pi p : v){
                    visited[p.first][p.second]=0;
                }
            }
            ans+=res;
            v.clear();
        }
    }
    cout << ans;
    return 0;
}