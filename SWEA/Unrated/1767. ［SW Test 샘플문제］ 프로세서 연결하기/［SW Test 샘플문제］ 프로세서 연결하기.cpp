#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()


int n,arr[15][15];
vector<pi> core; // 코어 위치 저장 벡터
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int maxCore=20, minSum=0;


bool check(int x,int y, int d){ // (x,y) 좌표에서 d 방향으로 연결할 수 있는지 확인

    x+=dx[d];
    y+=dy[d];
    while(x >= 0 && x < n && y >= 0 && y < n){
        if(arr[x][y]==1) return false;
        x += dx[d];
        y += dy[d]; 
    }
    return true; // 연결 가능
}

void recur(int index, int coreCnt, int wireSum){
    if(index == core.size()){
        //cout << coreCnt << ' ' << wireSum << '\n';
        if(maxCore < coreCnt){ // 코어 수가 더 많으면 무조건 갱신
            maxCore = coreCnt;
            minSum = wireSum;
        } else if(maxCore == coreCnt) minSum = min(minSum,wireSum); // 코어 수가 같으므로 sum 크기 비교
        return;
    }
    int x = core[index].first; // core X 좌표
    int y = core[index].second;// core Y 좌표

    for(int i=0;i<4;i++){ // 4 방향
        if(check(x,y,i)){ // 연결할 수 있는지 확인
            int nx = x+dx[i], ny = y+dy[i];
            int sum=0;
            while(nx >= 0 && nx < n && ny >= 0 && ny < n){ // 전선 연결
                arr[nx][ny]=1;
                sum++;
                nx += dx[i];
                ny += dy[i];
            }
            recur(index+1,coreCnt+1,wireSum+sum);
            nx = x+dx[i], ny = y+dy[i];
            while(nx >= 0 && nx < n && ny >= 0 && ny < n){ // 연결 해제
                arr[nx][ny]=0;
                nx += dx[i];
                ny += dy[i];
            }

        }
    }
    recur(index+1,coreCnt,wireSum);
}
int main()
{
    FASTIO
    int T; cin >> T;
    for(int tc=1;tc<=T;tc++){
        cin >> n;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> arr[i][j];
                if(i!=0 && i!= n-1 && j!=0 && j!=n-1 && arr[i][j]==1){ // 가장자리 코어는 저장 X
                    core.push_back({i,j});
                }
            }
        }

        minSum=10000;
        maxCore=0;

        recur(0,0,0);

        cout << "#" << tc << " " << minSum << '\n';

        core.clear();
    }
    return 0;
}


