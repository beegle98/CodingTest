//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int p(int a,int b){
	if(b<1) return 1;
	return a*p(a,b-1);
}

int main(){
 
    int ans=0,T=10;
    for(int t=1;t<=T;t++){

		int tc; cin >> tc;
		int a,b; cin >> a >> b;
		
		ans = p(a,b);
		
        cout << "#" << tc << ' ' << ans << '\n';
    }
    return 0;
}
