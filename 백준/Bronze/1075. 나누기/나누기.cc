#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);

int main()
{
    FASTIO
    int n,f; cin >> n >> f;
    n = n - (n%100);
    for(int i=0;i<f;i++){
        if((n+i)%f==0){
            printf("%02d\n",i);
            break;
        }
    }
    return 0;

}
