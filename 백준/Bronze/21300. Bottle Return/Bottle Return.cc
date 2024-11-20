#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;



int main(){
    int s[6], sum=0;
    for(int i=0;i<6;i++){
        cin>>s[i];
        sum += s[i];
    }
    cout<<sum*5;
    return 0;
}

