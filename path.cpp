#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
queue <pair <int, int>> q;
int w, l, x, y, x1, y1;

vector <vector <pair <int, int>>> a(N);
int depth[N][N];
int arr[N][N];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    a.resize(N);
    
    cin >> w >> l >> x >> y >> x1 >> y1;
    for (int i = 0; i < w; i ++) {
        for (int j = 0; j < l; j ++) {
            cin >> arr[i][j];
            a[arr[i][j]].push_back({i, j});
        }   
    }
    
    q.push({x, y});
    
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i ++) {
            int newa = a + dx[i];
            int newb = b + dy[i];
            if (newa < 0 || newa > l-1) continue;
            if (newb < 0 || newb > w-1) continue;
            if (arr[newa][newb] == 0) continue;
            
            depth[newa][newb] = depth[a][b] + 1;
            q.push({newa, newb});
        }
        
        for (pair i : a[(arr[a][b])]) {
            int newa = i.first;
            int newb = i.second;
            depth[newa][newb] = depth[a][b] + 1;
            
            q.push({newa, newb});
        }
    }
    
    cout << depth[x1][y1];
    
    return 0;
}
