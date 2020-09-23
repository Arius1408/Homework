#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector <int> a(N);
int t = 0;
int n;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    a.resize(N);
    
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    for (int i = 0; i < (int)a.size(); i ++) {
        for (int j = i+1; j < (int)a.size(); j ++) {
            for (int k = j +1; k < (int)a.size(); k ++) {
                if (a[k] - a[j] > a[i]) break;
                if (a[k]*a[k] < a[i]*a[i] + a[j]*a[j]) t ++;
            }
        }
    }
    
    cout << t;
    
    return 0;
}
