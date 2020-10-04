#include <iostream>
#include <vector>
using namespace std;

#define gr(v, tm, tl) v+2*(tm-tl+1)
#define gl(v) v+1
typedef pair <int, int> pii;

const int N = 1e8;
pii t[2*N];
int a[N];

pii combine(pii a, pii b) {
    if (a.first > b.first) return a;
    if (b.first > a.first) return b;
    
    return make_pair(a.first, a.second+b.second);
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v].first = a[tl];
        t[v].second = 1;
    } else {
        int tm = (tl+tr)/2;
        build(a, gl(v), tl, tm);
        build(a, gr(v, tm, tl), tm+1, tr);
        t[v] = combine(t[gl(v)], t[gr(v, tm, tl)]);
    }
}

int n, l, r;

void solveProblem() {
    
    cin >> n >> l >> r;
    
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    
    build(a, 0, 0, n-1);
    cout << t[0].first << " " << t[0].second;
}

int main () {
    //freopen("output.txt", "w", stdout);
    //freopen("input.txt", "r", stdin);
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    solveProblem();
    return 0;
}
