#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int arr[100001];

int main(){
    FASTIO
    int n,x; cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    cin >> x;
    sort(arr,arr+n);
    int l=0,r=n-1;
    ll sum=0;
    while(l<r){
        int S=arr[l]+arr[r];
        if(S==x){
            sum++;
            r--;
        }
        else if(S>x){
            r--;
        }
        else{//S<x
            l++;
        }
    }
    cout << sum;
}