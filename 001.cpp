#include <iostream>
#include <vector>

const int width = 5000 * 2 + 10;

std::pair <int, int> curr = {5000, 5000};

// 0 = forward, 1 = left, 2 = back, 3 = right
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

std::vector <std::vector <int>> depth(width);
std::vector <std::vector <bool>> used(width);

void prepare() {

    for (int i = 0; i < width; i ++) {
        depth[i].resize(width);
        used[i].resize(width);
    }

    used[curr.first][curr.second] = true;
}

void move(int &key) {

    int x = curr.first + dx[key];
    int y = curr.second + dy[key];
    
    if (used[x][y]) {
        curr.first = x;
        curr.second = y;
        return;
    }
    
    used[x][y] = true;
    int min = 100000000;

    for (int i = 0; i < 4; i ++) {

        int newx = x + dx[i];
        int newy = y + dy[i];

        if (!used[newx][newy]) continue;
        min = std::min(min, depth[newx][newy]);
    }

    depth[x][y] = min + 1;
    curr.first = x;
    curr.second = y;
}



int nTest, k;

int main (int argc, const char * argv[]) {
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    prepare();
    std::cin >> nTest;

    while (nTest --) {
        std::cin >> k;
        move(k);
    }

    std::cout << depth[curr.first][curr.second] << "\n";

    return 0;
}
