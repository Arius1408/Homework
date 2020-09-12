#include <iostream>
#include <algorithm>
#include <vector>

int test;
int n, h;

bool possible(int &s, int &h, std::vector <int> &arr) {

	long long t = 0;

	for (int i = 0; i < arr.size(); i ++) {
		t += (arr[i] / s + 1);
	}

	if (t <= h) return true;
	else return false;
}

int minTime(int &n, int &h, std::vector <int> &arr) {

    int l = 1000000000 + 10;
    int r = -1;

    for (int x : arr) {
        l = std::min(l, x);
        r = std::max(r, x);
    }

    if (h == arr.size()) return r;

	while (l < r) {
		int mid = (l+r+1)/2;
		if (possible(mid, h, arr)) {
			r = mid;
		} else {
			l = mid+1;
		}
	}

	return l-1;
}

int main (int argc, const char * argv[]) {
    
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> test;

	while (test --) {
		std::cin >> n >> h;
		std::vector <int> arr(n);

        for (int i = 0; i < n; i ++) {
            std::cin >> arr[i];
        }

		std::cout << minTime(n, h, arr) << "\n";
	}

	return 0;
}
