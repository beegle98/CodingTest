#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

inline int sub(int x, int r){
    return (x-1+r)%r;
}
inline int add(int x,int r){
    return (x+1)%r;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
	int n,k; cin >> n >> k;
    int N = 2*n;
    vi con(N), a(N);
    for(int i=0;i<N;i++) cin >> a[i];
    int turn=0, cnt=0;
    int st=0; // 로봇 올리는 위치
    int ed=n-1; // 로봇 내리는 위치
    while(cnt<k){
        turn++;
        st=sub(st,N); // 컨테이너 이동
        ed=(st+n-1)%N;
        con[ed]=0; // 로봇 내리기
        for(int i=ed;i!=sub(st,N);i=sub(i,N)){
            int nx = add(i,N);
            if(con[i]==1 && con[nx]==0 && a[nx]>0){
                con[i]=0;
                con[nx]=1;
                a[nx]--;
                if(a[nx]==0) cnt++;
            }
        }
        con[ed]=0;
        if(con[st]==0 && a[st]>0){
            con[st]=1;
            a[st]--;
            if(a[st]==0) cnt++;
        }
    }
    cout << turn;
    return 0;
}