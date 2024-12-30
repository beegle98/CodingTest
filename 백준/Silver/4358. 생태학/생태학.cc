#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


int main() {

    int sum = 0;
    map<string, double> m;
    string str;
    while (getline(cin,str)) {
        m[str]++;
        sum++;
    }
    for(auto itr = m.begin(); itr!=m.end(); itr++){
        printf("%s %.4lf\n", itr->first.c_str(), itr->second * 100 / sum);
    }
    return 0;
}