#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;
#define FASTIO  cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()

bool cmp(const pi& t1, pi& t2){
    if(t1.second == t2.second){
        t1.first < t2.second;
    }
    else return t1.second > t2.second;
}

int main()
{
    FASTIO
    int N, K; cin >> N >> K;

    vector<pi> arr(N); // 무게, 가격
    multiset<int> bp; // 가방
    for(int i=0;i<N;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(all(arr),cmp);
    for(int i=0;i<K;i++){
        int x; cin >> x;
        bp.insert(x);
    }
    ll sum=0;
    for(int i=0;i<N;i++){
        //cout << arr[i].second << '\n';
        auto iter = bp.lower_bound(arr[i].first);
        if(iter != bp.end()){// 넣을 가방 있음
            bp.erase(iter);
            sum +=arr[i].second;
        }
    }
    cout << sum;
    return 0;
}
