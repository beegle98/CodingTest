#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

const int N = 100010;

int n,q;
vll arr(N), tree(4*N);

ll init(int node, int s, int e){
    if(s==e) return tree[node] = arr[s];
    int m = (s+e)/2;
    return tree[node] = init(node*2,s,m) + init(node*2+1,m+1,e);
}

void update(int node, int s, int e, int idx, int val){
    if(s>idx || e<idx) return;
    if(s==e){
        tree[node] = val;
        return;
    }
    int m = (s+e)/2;
    update(node*2,s,m,idx,val);
    update(node*2+1,m+1,e,idx,val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll sum(int node, int s, int e, int l, int r){
    if(s>r || e<l) return 0;
    if(s>=l && e<=r) return tree[node];
    int m = (s+e)/2;
    return sum(node*2,s,m,l,r) + sum(node*2+1,m+1,e,l,r);    
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
	
    cin >> n >> q;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    init(1,1,n);
    for(int i=0;i<q;i++){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        if (x>y){
            int tmp = x;
            x = y;
            y = tmp;
        }
        ll res = sum(1,1,n,x,y);
        update(1,1,n,a,b);
        cout << res << '\n';
    }
    return 0;
}