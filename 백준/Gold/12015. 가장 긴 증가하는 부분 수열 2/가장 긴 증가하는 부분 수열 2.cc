#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;

int n,v[1000001];
vector<int> LIS;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


    cin >> n;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    
    LIS.push_back(v[0]);
    for(int i=1;i<n;i++){
        if(LIS.back() < v[i]){
            LIS.push_back(v[i]);
        }
        else{
            auto iter = lower_bound(LIS.begin(), LIS.end(), v[i]);
            *iter = v[i];
        }
        
    }
    cout << LIS.size() << '\n';
    
    return 0;
}