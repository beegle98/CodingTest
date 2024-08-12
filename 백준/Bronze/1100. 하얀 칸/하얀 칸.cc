#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int main(){
    FASTIO
    int sum=0;
    char arr[10][10];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> arr[i][j];
            if(arr[i][j]=='F' && (i+j)%2==0) sum++;
        }
    }
    cout << sum;
}