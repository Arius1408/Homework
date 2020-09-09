#include <iostream>
#include <vector>

// Assume that the limit length is 5000
std::vector <bool> status[10000];
std::vector <int> depth[10000];

// Declare the value for later navigate
// 0 = forward, 1 = left, 2 = back, 3 = right
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

// Declare our current status
std::pair <int, int> curr;

void clear() {

    curr.first = 5000;
    curr.second = 5000;
    depth[5000][5000] = true;
}

// Calculate our shortest path with every key we have
void move(int &direction) {

    // Decalre our new position
    int x = curr.first + dx[direction];
    int y = curr.second + dy[direction];

    // Return the shortest path if we're already there before
    if (status[x][y]) {
        curr.first = x;
        curr.second = y;

        return;
    }

    // If we' re not there before
    status[x][y] = true;
    curr.first = x;
    curr.second = y;

    // Then calculate the shortest path
    int min = 10000 + 10;
    for (int i = 0; i < 4; i ++) {

        // look for an used square with minimum value of step
        int newx = x + dx[i];
        int newy = y + dy[i];

        if (status[newx][newy] == true 
        && depth[newx][newy] < min) 
            min = depth[newx][newy];
    }

    depth[x][y] = min + 1;
}

int main (int agrc, const char * argv[]) {

    std::ios_base::sync_with_stdio(false);
    freopen("cin.txt", "r", stdin);
    freopen("cout.txt", "w", stdout);

    curr.first = 5000;
    curr.second = 5000;
    depth[5000][5000] = true;

    std::cout << curr.first << "\n";
    std::cout << curr.second;

    return 0;
}


