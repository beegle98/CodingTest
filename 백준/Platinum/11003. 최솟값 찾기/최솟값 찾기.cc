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

typedef struct{
    int data;
    int index;
}DATA;
struct cmp{
    bool operator()(const DATA& t1, const DATA& t2){
        return t1.data > t2.data; // 내림차순
    }
};

priority_queue<DATA,vector<DATA>,cmp> pq;

int main()
{
    FASTIO
    int N, L;
    cin >> N >> L;
    vi arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    for(int i=0;i<N;i++){
        
        pq.push({arr[i],i});
        
        while(pq.top().index < i-L+1) pq.pop();

        cout << pq.top().data << ' ';
    }
    return 0;
}
