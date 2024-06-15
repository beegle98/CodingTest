#include <bits/stdc++.h>

using namespace std;
#define FASTIO  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

vi LIS, arr, LDS;

int main()
{
    FASTIO
    int ans=0, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        LIS.push_back(arr[i]);
        LDS.push_back(arr[i]);
        for (int j = i+1; j < arr.size(); j++)
        {
            
            if (LIS.back() < arr[j]){
                LIS.push_back(arr[j]);
            }
            else if(LIS.front() < arr[j]){
                int itr = lower_bound(LIS.begin(), LIS.end(), arr[j]) - LIS.begin();
                LIS[itr] = arr[j];
            }
            if (LDS.back() > arr[j]){
                LDS.push_back(arr[j]);
            }
            else if(LDS.front() > arr[j]){
                int itr = lower_bound(LDS.begin(), LDS.end(), arr[j],greater<int>()) - LDS.begin();
                LDS[itr] = arr[j];
            }
        }
        
        int sum = LIS.size()+LDS.size()-1;
        ans = max(ans,sum);
        LIS.clear();
        LDS.clear();
    }
    cout << ans;

    return 0;
}
