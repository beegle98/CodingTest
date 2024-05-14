#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

stack<int> s;
int arr[1001];

int main(){
    FASTIO
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int cnt=1;
    for(int i=0;i<n;i++){
        if(arr[i]==cnt) cnt++;
        else{
            if(!s.empty() && s.top()==cnt){
                s.pop();
                cnt++;
                i--;
            }
            else{
                s.push(arr[i]);
            }
        }
    }
    while(!s.empty()){
        if(s.top()==cnt){
            cnt++;
            s.pop();
        }
        else break;
    }
    if(cnt==n+1) cout << "Nice";
    else cout << "Sad";
    return 0;
}
