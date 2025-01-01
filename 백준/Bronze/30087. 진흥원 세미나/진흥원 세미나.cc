#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, string> m;
    m["Algorithm"] = "204";
    m["DataAnalysis"] = "207";
    m["ArtificialIntelligence"] = "302";
    m["CyberSecurity"] = "B101";
    m["Network"] = "303";
    m["Startup"] = "501";
    m["TestStrategy"] = "105";
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        cout << m[s] << '\n';
    }
    
    return 0;
}