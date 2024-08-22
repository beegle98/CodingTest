#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef pair<int, pair<int, int>> pi;
 
int main() {
    int a, b;
    while(cin >> a >> b){
        cout << b/(a+1) << '\n';
    }
    return 0;
}