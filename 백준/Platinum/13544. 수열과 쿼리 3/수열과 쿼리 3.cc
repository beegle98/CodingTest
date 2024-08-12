#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()

const int MAX = 100005;
vi tree[MAX*2];
int n,arr[MAX];

int query(int l, int r, int k){
    l += n, r += n;
    int ret = 0;
    while(l <= r){
        if(l & 1) ret += tree[l].end() - upper_bound(all(tree[l]), k), l++;
        if(~r & 1) ret += tree[r].end() - upper_bound(all(tree[r]), k), r--;
        l >>= 1, r >>= 1;
    }
    return ret;
}

int main()
{
    FASTIO
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        tree[n+i].push_back(arr[i]);
    }
    for(int i=n-1;i;i--){
        tree[i].resize(tree[i*2].size() + tree[i*2+1].size());
        merge(all(tree[i*2]), all(tree[i*2+1]), tree[i].begin());
    }
    int m; cin >> m;
    int ans=0;
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        a = a ^ ans;
        b = b ^ ans;
        c = c ^ ans;
        ans = query(a,b,c);
        cout << ans << '\n';
    }
    return 0;

}


