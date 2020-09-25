#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;

int t, n, l, r;
int a[N];
int pl[N];
int m = -1;
int p = 0;

int main () {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t >> n;

	for (int i = 0; i < t; i ++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i ++) {
		cin >> l >> r;

		if (l <= r) {
			pl[l] += 1;
			pl[r+1] -= 1;
		} else {
			pl[0] += 1;
			pl[l] += 1;
			pl[r+1] -= 1;
		}
	}

	for (int i = 0; i < t; i ++) {
		if (pl[i] != 0) {
			p += pl[i];
		}
		a[i] += p;
		m = max(a[i], m);
	}
	
	cout << m;

	return 0;
}
