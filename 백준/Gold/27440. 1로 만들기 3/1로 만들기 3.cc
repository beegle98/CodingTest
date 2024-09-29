#include<bits/stdc++.h>
#include <unordered_set>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;


ll bfs(pll start){
    queue<pll> q;
    unordered_set<ll> visited;
    ll res=0;
    q.push(start);
    visited.insert(start.first);

    while(!q.empty()){
        pll p = q.front();
        q.pop();
        ll n = p.first, cnt=p.second;
        if(n==1){
            res=cnt;
            break;
        }
        if(n%3==0 && visited.find(n/3)==visited.end()){
            q.push({n/3,cnt+1});
            visited.insert(n/3);
        }
        if(n%2==0 && visited.find(n/2)==visited.end()){
            q.push({n/2,cnt+1});
            visited.insert(n/2);
        }
        if(visited.find(n-1)==visited.end()){
            q.push({n-1,cnt+1});
            visited.insert(n-1);
        }
    }
    return res;
}

int main(){


    ll n; cin >> n;
    ll ans=bfs({n,0});
    cout << ans;
    return 0;
}