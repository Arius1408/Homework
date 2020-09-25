#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector <vector <pair <int, int>>> a;
queue <pair <int, int>> q;
int depth[N][N];
int arr[N][N];

void clearData() {
    a.resize(N);
}

int w, l, x, y, x1, ny;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main () {
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    clearData();
    cin >> w >> l >> x >> y >> x1 >> ny;

    for (int i = 0; i < w; i ++) {
        for (int j = 0; j < l; j ++) {
            cin >> arr[i][j];
            if (arr[i][j]) a[arr[i][j]].push_back({i, j});
        }
    }

    q.push({x, y});

    while(!q.empty()) {
        int c = q.front().first;
        int d = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i ++) {
            int newc = c + dx[i];
            int newd = d + dy[i];

            if (newc < 0 || newc >= w) continue;
            if (newd < 0 || newd >= l) continue;
            if (arr[newc][newd] == 0) continue;

            if (depth[newc][newd] == 0) {
                depth[newc][newd] = depth[c][d] + 1;
            } else {
                depth[newc][newd] = min(depth[newc][newd], (depth[c][d] + 1));
            }
            if (newc == x1 && newd == ny) {
                cout << depth[x1][ny];
                return 0;
            }
            q.push({newc, newd});
        }

        for (pair <int, int> i : a[arr[c][d]]) {
            if (i.first != x && i.second != d) {
                int newc = i.first, newd = i.second;
                if (depth[newc][newd] == 0) {
                    depth[newc][newd] = depth[c][d] + 1;
                } else {
                    depth[newc][newd] = min(depth[newc][newd], (depth[c][d] + 1));
                }
                if (i.first == x1 && i.second == ny) {
                    cout << depth[x1][ny];
                    return 0;
                }
                q.push({i.first, i.second});
            }
        }
    }

    return 0;
}
