#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define FASTIO  cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()

priority_queue<int,vector<int>,greater<int>> pq;

int main()
{
    FASTIO
    int n; cin >> n;
    vector<pi> arr;
    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        arr.push_back({x,y});
    }
    sort(all(arr));
    
    for(int i=0;i<arr.size();i++){
        pq.push(arr[i].second);
        if(pq.top() <= arr[i].first) pq.pop();
    }
    cout << pq.size();

    return 0;
}
