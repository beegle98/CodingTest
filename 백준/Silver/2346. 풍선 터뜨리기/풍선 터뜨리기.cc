#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;


int main(){
    
    int n,arr[1001]; cin >> n;
    for(int i=1;i<=n;i++){
       cin >> arr[i];
    }
    arr[0]=0;
    int t,index=1;
    for(int i=0;i<n-1;i++){
        cout << index << ' ';
        t=arr[index];
        arr[index]=0;
        if(t>0){
            for(int j=0;j<t;j++){
                index=index%n+1;
                if(arr[index]==0) j--;
            }
        }
        else{
            t=-t;
            for(int j=0;j<t;j++){
                index--;
                if(index==0) index=n;
                if(arr[index]==0) j--;
            }
        }
    }
    cout << index;
    return 0;
}

