#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>


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

deque<DATA> dq;

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
        
        while(!dq.empty() && dq.back().data > arr[i]) dq.pop_back();
        dq.push_back({arr[i],i});
        
        if(dq.front().index < i-L+1) dq.pop_front();

        cout << dq.front().data << ' ';
    }
    return 0;
}
