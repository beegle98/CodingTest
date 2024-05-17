#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);

int main(){
    FASTIO
    int n,x1,x2,y1,y2; cin >> n;
    cin >> x1 >> y1;
    x2=x1;
    y2=y1;
    for(int i=1;i<n;i++){
        int x,y; cin >> x >> y;
        if(x1>x) x1=x;
        if(x2<x) x2=x;
        if(y1>y) y1=y;
        if(y2<y) y2=y; 
    }
    cout << (y2-y1)*(x2-x1);
    return 0;
}

