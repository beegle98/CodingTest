#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()

int n,m, ans = -1;
char arr[11][11];
bool visited[11][11][11][11]; // 앞 두 칸= red , 뒤 두 칸 = blue
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
pi ex;

typedef struct{
	pi red_pos;
	pi blue_pos;
	int cnt;
}Position;

queue<Position> q;



void move(Position p, int d){ // visited 확인, red 먼저 움직임, b가 바로 앞에 있으면 b 먼저 움직임
	// 움직이는 사이에 떨어지는 코드 추가
	// 출구에 도착하면 더이상 못움직이게 추가

	pi nr = p.red_pos, nb = p.blue_pos; // red, blue 위치
	int stop_r=0, stop_b=0;
	while(1){
		//cout << d << '\n';
		//cout << nr.first << ", " << nr.second << " | " << nb.first << ", " << nb.second << '\n';
		stop_r=0, stop_b=0;
		if(nr != ex){
			nr.first += dx[d];
			nr.second += dy[d];
		}
		if(nr == ex){
			stop_r=1;
			nb.first += dx[d];
			nb.second += dy[d];
			if(nb == ex) return;
			else if(arr[nb.first][nb.second]=='#'){
				nb.first -= dx[d];
				nb.second -= dy[d];
				stop_b=1; // blue 다시 돌아옴
			}
		}
		else if(arr[nr.first][nr.second]=='#'){
			nr.first -= dx[d];
			nr.second -= dy[d];
			stop_r=1; // red 다시 돌아옴
			nb.first += dx[d];
			nb.second += dy[d];
			if(nb == ex) return;
			else if(arr[nb.first][nb.second]=='#' || nb==nr){
				nb.first -= dx[d];
				nb.second -= dy[d];
				stop_b=1; // blue 다시 돌아옴
			}
		}
		else if(nr == nb){// 앞이 blue임
			nb.first += dx[d];
			nb.second += dy[d];
			if(nb == ex) return;
			else if(arr[nb.first][nb.second]=='#'){
				nb.first -= dx[d];
				nb.second -= dy[d];
				stop_b=1; // blue 다시 돌아옴
				nr.first -= dx[d];
				nr.second -= dy[d];
				stop_r=1; // red 다시 돌아옴
			}

		}
		
		else{// '.' or 'O'
			// Red가 있던 곳이니 조건 없이 +
			nb.first += dx[d];
			nb.second += dy[d];
			if(nb == ex) return;
			else if(arr[nb.first][nb.second]=='#' || nb==nr){
				nb.first -= dx[d];
				nb.second -= dy[d];
				stop_b=1; // blue 다시 돌아옴
			}
		}
		if( stop_r && stop_b){ 
			break;
		}
		
	}

	if(!visited[nr.first][nr.second][nb.first][nb.second]){
		Position tmp;
		tmp.red_pos=nr;
		tmp.blue_pos=nb;
		tmp.cnt = p.cnt+1;
		q.push(tmp);
	}
}


void bfs(Position p){
	if(p.cnt>10){
		while(!q.empty()) q.pop(); // 큐 clear
		return;
	}
	if(p.blue_pos == ex){ // Blue가 출구 도착 => 펑
		return;
	}
	else if(p.red_pos == ex){ // Red가 출구 도착 => 끝
		ans = p.cnt;
		while(!q.empty()) q.pop(); // 큐 clear
		return;
	}
	
	visited[p.red_pos.first][p.red_pos.second][p.blue_pos.first][p.blue_pos.second]=true;

	for(int i=0;i<4;i++){
		move(p,i);
	}
}


int main()
{
	cin >> n >>m;
	Position st;
	st.cnt=0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		for(int j=0;j<m;j++){
			if(arr[i][j]=='B'){
				arr[i][j]= '.';
				st.blue_pos.first = i;
				st.blue_pos.second = j;
			}else if(arr[i][j]=='R'){
				arr[i][j]= '.';
				st.red_pos.first = i;
				st.red_pos.second = j;
			}else if(arr[i][j]=='O'){
				ex.first=i;
				ex.second=j;
			}
		}
	}
	q.push(st);
	while(!q.empty()){
		Position tmp = q.front();
		q.pop();
		bfs(tmp);
	}
	cout << ans;

	return 0;
}
