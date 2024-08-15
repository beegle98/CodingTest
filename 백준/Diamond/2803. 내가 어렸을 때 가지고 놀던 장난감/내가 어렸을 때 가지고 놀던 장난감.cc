#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


const int MAX=(1<<20);
const int MOD = 1e9 + 7;

int DP[MAX];// DP[mask] = "mask에 속하는 원소들을 가지고있지 않는 상자의 수"
int DP2[MAX];// DP[mask] = "mask에 속하는 원소들을 가지고있지 않는 상자의 수"
int N,M;

inline int Add(int a, int b) { return (a + b) % MOD; }
inline int Sub(int a, int b) { return (a - b + MOD) % MOD; }
inline int Pow(int x, int n) {
	int ret = 1;
	for (; n; n >>= 1) {
		if (n & 1) ret = (1LL * ret * x) % MOD;
		x = (1LL * x * x) % MOD;
	}
	return ret;
}

void input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        int state = 0, k; cin >> k;
        for(int j=0;j<k;j++){
            int x; cin >> x;
            state |= 1<<x-1;
        }
        DP[state]++; // 바로 DP[]에 넣어서 v[]생략
    }
    //v[mask] = "mask에 속하는 원소들을 갖고있는 상자의 수"
}

int solve(){

    input();
    
    //for(int i=0;i< 1<<M;i++) DP[i]=v[i]; v[] 생략
    
    // SOS DP
	for (int i = 0; i < M; i++) for (int mask = 0; mask < 1 << M; mask++)
		if (mask & 1 << i) DP[mask] = Add(DP[mask], DP[mask ^ 1 << i]);

    // DP[mask] = "mask에 속하는 원소들을 가지고있지 않는 상자의 수"
	// get DP
	for (int i = 0; i < 1 << M - 1; i++) swap(DP[i], DP[i ^ (1 << M) - 1]);
	for (int i = 0; i < 1 << M; i++) DP2[i] = Pow(2, DP[i]);


    // DP2[mask]를 "mask에 속하는 원소들을 가지고있지 않도록 상자를 고르는 경우의 수"
    // DP[0] = 모든 경우의 수, DP[1] = 1을 가지고 있지 않은 모든 경우의 수
    // DP[2](11) = 1, 2를 가지고 있지 않은 모든 경우의 수
    // 가지고 있지 않은 경우를 구하는 이유 = 가지고 있는 경우의 수는 구하기 어렵기 때문에

    //포함 배제의 원리 => 비트 개수 순서대로 더하고 빼고(짝수는 더하고 홀수는 빼고)
    int sum=0;
    //__builtin_popcount(i) 비트 개수 세는 함수
    for (int i = 0; i < 1 << M; i++) {
		if (__builtin_popcount(i) & 1) sum = Sub(sum, DP2[i]);
		else sum = Add(sum, DP2[i]);
	}
    return sum;
}

int main()
{
    FASTIO
    int ans;
    ans = solve();
    cout << ans << '\n';
    return 0;
}