#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()

multiset<int> dual_pq;

int main()
{
    FASTIO
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc;t++){
        int n;
        cin >> n;
        for (int i = 0; i < n;i++){
            char c;
            cin >> c;
            int x;
            cin >> x;
            if(c=='I'){
                dual_pq.insert(x);
            }
            else if(c=='D'){
                if(dual_pq.empty()) continue;
                if(x==1){ // 최댓값 제거
                    dual_pq.erase(--dual_pq.end());
                }else if(x==-1){// 최솟값 제거
                    dual_pq.erase(dual_pq.begin());
                }
            }else {
                continue;
            }
        }
        if(dual_pq.empty()){
            cout << "EMPTY\n";
        }else{
            cout << *(--dual_pq.end()) << ' ' << *dual_pq.begin() << '\n';
        }
        dual_pq.clear();
    }
    return 0;
}
