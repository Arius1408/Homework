#include <bits/stdc++.h>
using namespace std;
#define gm(a, b) (((b*b+1) / 2 - a*(a+1)/2) / 2)
#define cm(x, y) (y*(y+1) / 2 - x*(x+1)/2)
typedef long long ll;

ll l, r;

void solveProblem() { // Bai nao cua em cung co cai ham solveProblem() nay
    cin >> l >> r;
    ll mid = gm(l, r);

    ll left = l;

    while (l < r) {
        ll m = (l + r)/2;

        if (cm(left, m) >= mid) {
            r = m;
        } else {
            l = m+1;
        }
    }

    cout << l;
}

int main () { // Bai nao cua em cung co cai form ham main() nhu the nay
    freopen("BAI1.inp", "r", stdin);
    freopen("BAI1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solveProblem();
    return 0;
}
