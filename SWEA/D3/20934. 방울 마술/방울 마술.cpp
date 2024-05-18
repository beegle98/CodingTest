#include <iostream>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);

int main(){
    FASTIO

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int ans,x,k;
        char s[10]; cin >> s >> k;
        for(int i=0;i<3;i++){
            if(s[i]=='o') x=i; 
        }
        if(k==0) ans = x;
        else{
            k+=x%2;
            k%=2;
            ans=k;
        }
        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}
