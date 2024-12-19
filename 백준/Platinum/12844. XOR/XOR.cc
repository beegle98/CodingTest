#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N = 500001; 

vll tree, arr, lazy;

ll init(int node, int start, int end){
    if(start == end){
        return tree[node] = arr[start];
    }
    return tree[node] = init(node*2, start, (start+end)/2)
        ^ init(node*2+1,(start+end)/2+1, end);
}
void update_lazy(int node, int start, int end){
    if(lazy[node] != 0){ 
        tree[node] ^= lazy[node] * ((end-start+1)%2); 
        if(start != end){ 
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int left, int right, ll diff){
    update_lazy(node, start, end);

    if(left>end || right<start){ 
        return;
    }
    if(left<=start && end<=right){ 
        tree[node] ^= diff * ((end-start+1)%2); 
        if(start != end){ 
            lazy[node*2] ^= diff;
            lazy[node*2+1] ^= diff;
        }
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}
ll query(int node, int start, int end, int left, int right){
    update_lazy(node,start,end);
    if(left > end || right < start) return 0;
    if(left <= start && right >= end){
        return tree[node];
    }
    return query(node*2, start, (start+end)/2, left, right)
        ^ query(node*2+1, (start+end)/2+1, end, left, right);
}


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, m;
    cin >> n;
    arr = vll(n);
    tree = vll(4*n);
    lazy = vll(4*n);
    for(int i=0;i<n;i++) cin >> arr[i];
    init(1,0,n-1);
    cin >> m;
    

    for(int i=0;i<m;i++){
        int op; cin >> op;
        if(op == 1){
            int a, b, c; cin >> a >> b >> c;
            update_range(1,0,n-1,a,b,c);
        }else{
            int a, b; cin >> a >> b;
            cout << query(1,0,n-1,a,b) << '\n';
        }
    }
    
    return 0;
}