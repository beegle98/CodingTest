#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int a, b; cin >> a >> b;

	if (a * 2 >= b) cout << "E";
	else cout << "H";

	return 0;
}