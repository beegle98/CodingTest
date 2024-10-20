#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

struct dotori{
    int start;
    int end;
    int interval;
    dotori(int a, int b, int c){
        start = a;
        end = b;
        interval = c;
    }
};

int n, k;
ll D;

vector<dotori> v;

ll cntDotori(int idx){
    ll res=0;
    for(int i=0;i<k;i++){
        if(idx < v[i].start) continue;
        else if(idx > v[i].end) res += (v[i].end-v[i].start)/v[i].interval + 1;
        else res += (idx-v[i].start)/v[i].interval + 1;
    }
    return res;
}

int solve(){
    
    int st = 1, ed = n, mid;
    while(st+1<ed){
        mid = (st+ed)/2;
        ll cnt = cntDotori(mid);
        //cout << st << ", " << ed << " : " << mid << " " << cnt << '\n';
        if(cnt>=D){
            ed = mid;
        }else{
            st = mid;
        }
    }
    return ed;
}

int main(){
    cin >> n >> k >> D;
    for(int i=0;i<k;i++){
        int a,b,c; cin >> a >> b >> c;
        v.push_back({a,b,c});
    }
    int ans = solve();
    cout << ans;
    return 0;
}