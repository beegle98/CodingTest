#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()

int n,m,ans;
int dx[4] = {-1,0,1,0};// 방향
int dy[4] = {0,1,0,-1};// 0~3 순서대로 북,동,남,서
int arr[100][100];

bool check(int x,int y){ // 4 방향에 빈칸이 있는지 확인
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && arr[nx][ny]==0) return true;
    }
    return false;
}

void dfs(int x,int y,int d){ // 탐색
    
    if(x<0 || x>=n || y<0 || y>=m) return;

    if(arr[x][y]==0){//1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
        arr[x][y]=2+ans;
        ans++;
    }
    if(check(x,y)){//3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
        d = (d-1+4)%4; // 반시계 90도 회전
        int nx = x+dx[d];
        int ny = y+dy[d];
        if(nx>=0 && nx<n && ny>=0 && ny<m && arr[nx][ny]==0){ // 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
            x = nx;
            y = ny;
        }
        dfs(x,y,d); // 1번으로 돌아간다.
    }
    else{//2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        int nx = x - dx[d];
        int ny = y - dy[d];
        if(nx<0 || nx>=n || ny<0 || ny>=m || arr[nx][ny]==1) return; //바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
        else{
            dfs(nx,ny,d); // 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
        }
    }
}

int main()
{
    FASTIO
    cin >> n >> m;
    int r,c,d; cin >> r >> c >> d;
       
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> arr[i][j];
    }
    ans=0;
    if(arr[r][c]==0) dfs(r,c,d);

    cout << ans;
    return 0;
}
