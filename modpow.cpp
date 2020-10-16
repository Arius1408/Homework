#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define ll long long

const int N = 1e8+1;
int m = 998244353;
int tt, n, d = 1;
int a[N], ans;
vector <int> v;
int temp;

void preprocess() {
    for (int i = 1; i < N; i ++) {
        a[i] = i;
    }

    for (int i = 2; i*i < N; i ++) {
        if (a[i] == i) {
            for (int j = i*i; j < N; j += i) {
                a[j] = i;
            }
        }
    }
}

void clearData() {
    v.clear();
    temp = n;
    d = 1;
}

int modpow(int n, int d) {
    if (d == 0) return 1;

    ll t = modpow(n, d/2);
    t = (t*t) % m;
    if (d % 2) t = (t*n) % m;
    return t;
}

void solve() {
    cin >> n;
    clearData();

    while (temp != 1) {
        v.eb(a[temp]);
        temp /= a[temp];
    }

    sort(v.begin(), v.end());
    v.eb(0);

    for (int i = 0; i < (int)v.size()-1; i ++) {
        for (int j = i; j < (int)v.size()-1; j ++) {
            if (v[j+1] != v[j]) {
                d *= (j-i+2);
                i = j;
                break;
            }
        }
    }

    ans = modpow(n, d/2);
    if (d % 2) ans = (ans * ((int)sqrt(n))) % m;
    cout << ans << "\n";
}

int main () {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    preprocess();
    cin >> tt;
    while (tt --) {
        solve();
    }
}
