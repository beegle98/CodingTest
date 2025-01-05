#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int MAX = 100001;

int sz, cnt, arr[MAX], Cnt[1000001];
int ans[MAX];

struct Query {
    int l, r, id;
    bool operator<(const Query& rhs) const {
        if (l / sz == rhs.l / sz) return r < rhs.r;
        return l / sz < rhs.l / sz;
    }
} qrr[MAX];

void add(int x) {
    if (Cnt[x]++ == 0) cnt++;
}

void del(int x) {
    if (--Cnt[x] == 0) cnt--;
}

int main() {
    int n; cin >> n;
    sz = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> qrr[i].l >> qrr[i].r;
        qrr[i].id = i;
    }
    sort(qrr, qrr + m);

    int l = 1, r = 1;
    add(arr[1]);
    for (int i = 0; i < m; i++) {
        while (qrr[i].l < l) add(arr[--l]);
        while (qrr[i].l > l) del(arr[l++]);
        while (qrr[i].r < r) del(arr[r--]);
        while (qrr[i].r > r) add(arr[++r]);
        ans[qrr[i].id] = cnt;
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << '\n';
}