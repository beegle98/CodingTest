#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main()
{
    int n=20;
    string s;
    double sum=0,score=0;

    for(int i=0;i<n;i++){
        string s,a; cin >> s;
        double b,grade; cin >> b;
        score+=b;
        cin >> a;
        if(a=="F") grade = 0;
        else if(a=="P"){
            score-=b;
            grade=0;
        }
        else{
            grade = 'E'-a[0];
            if(a[1]=='+') grade += 0.5;
        }

        sum += grade*b;
    }
    cout << sum/score;
    return 0;
}