#include <iostream>
#include <vector>

int test;
int n, h;

bool possible(int &s, int &h, std::vector <int> &arr) {

	int t = 0;

	for (int i = 0; i < arr.size(); i ++) {
		t += (arr[i] / s + 1);
	}

	if (t <= h) return true;
	else retur false;
}

int minTime(int &n, int &h, std::vector <int> &arr) {

	int l = n; int r = h;

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

		std::cout << minTime(n, h, arr) << std::endl;
	}

	return 0;
}
