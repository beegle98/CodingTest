#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()

int arr[200][200]; // 1~N
int n,k,l;
int dx[4] = {0,1,0,-1};// 방향
int dy[4] = {1,0,-1,0};// 0~3 순서대로 동,남,서,북
int ans,life=1;//
deque<pi> snake;

void dfs(int x,int y,int d,int current, int end){
	//cout << x << " : " << y << '\n';
	if(current>end) return;// 시간 끝
	if(x<1 || x>n || y<1 || y>n || arr[x][y]==2){ // 부딪힘
		life=0;
		return;
	}
	
	if(arr[x][y]==0){// 사과 아니면 꼬리 없앰
		arr[snake.back().first][snake.back().second]=0;
		snake.pop_back();
	}
	ans++;
	snake.push_front({x,y});
	arr[x][y]=2;
	dfs(x+dx[d],y+dy[d],d,current+1,end);
}

int main()
{
    FASTIO
    cin >> n >> k;
    
    for(int i=0;i<k;i++){
        int x,y; cin >> x >> y;
        arr[x][y]=1;
    }
    ans = 1;
    cin >> l;
	int cur=0;
	int x=1,y=1,d=0;
	arr[1][1]=1;
	snake.push_back({1,1});
	for(int i=0;i<l;i++){
		int time; cin >> time;
		char dir; cin >> dir;
		if(life) dfs(x+dx[d],y+dy[d],d,cur+1,time);
		x = x + dx[d]*(time-cur);
		y = y + dy[d]*(time-cur);
		if(dir=='D'){ // 반시계 90도 회전
			d = (d+1)%4;
		}
		else{ // 시계 90도 회전
			d = (d-1+4)%4;
		}
		cur = time;
	}
	if(life) dfs(x+dx[d],y+dy[d],d,cur+1,100000000);// 살아있으면 그대로 직진

    cout << ans;

    return 0;
}
