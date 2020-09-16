#include <iostream>
#include <vector>

typedef long long ll;
const int limit = 100000 + 10;

int n;
ll w, l;
ll le = 0, r = 0;
std::vector <std::pair <ll, ll>> data(limit);

bool possible(ll &key) {
    ll sum = 0;

    for (auto x : data) {
        x.first += x.second * key;
        if (x.first >= l) sum += x.first;
    }

    return sum >= w;
}

long long min_month() {
    r = w;

    while (le < r) {
        ll mid = (le+r)/2;
        if (possible(mid)) {
            r = mid;
        } else {
            le = mid + 1;
        }
    }

    return le;
}


int main (int argc, const char * argv[]) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n >> w >> l;
    data.resize(n);

    for (int i = 0; i < n; i ++) {
        std::cin >> data[i].first >> data[i].second;
    }

    std::cout << min_month();

    return 0;
}
