#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N=1000100;


vll tree;


ll sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && right >= end){
        return tree[node];
    }
    return sum(node*2, start, (start+end)/2, left, right)
        + sum(node*2+1, (start+end)/2+1, end, left, right);
}

void update(int node, int start, int end, int idx, ll val){
    if(idx<start || idx > end) return;
    if(start == end){
        tree[node]=val;
        return;
    }
    update(node*2, start, (start+end)/2, idx, val);
    update(node*2+1, (start+end)/2+1, end, idx, val);
    tree[node] = tree[node*2]+tree[node*2+1];
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,m,k;
    cin >> n >> m >> k;
    
    tree = vll(4*N);

    for(int i=1;i<=n;i++){
        ll a; cin >> a;
        update(1,1,N,i,a);
    }
    for(int i=0;i<m+k;i++){
        ll a; cin >> a;
        if(a==1){//update
            ll b,c; cin >> b >> c;
            update(1,1,N,b,c);
        }
        else if(a==2){// sum print
            ll b,c; cin >> b >> c;
            cout << sum(1,1,N,b,c) <<'\n';
        }
    }

    return 0;
}