#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const int MAX = 10;
int n,arr[MAX][MAX],r90[MAX][MAX],r180[MAX][MAX],r270[MAX][MAX];

int main()
{
    int tc; cin >> tc;
    for(int t=1;t<=tc;t++){
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> arr[i][j];
                r90[j][n-1-i]=arr[i][j];
                r180[n-1-i][n-1-j]=arr[i][j];
                r270[n-1-j][i]=arr[i][j];
            }
        }
        cout << "#" << t << '\n';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << r90[i][j];
            }
            cout << ' ';
            for(int j=0;j<n;j++){
                cout << r180[i][j];
            }
            cout << ' ';for(int j=0;j<n;j++){
                cout << r270[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}