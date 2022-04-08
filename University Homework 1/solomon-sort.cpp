#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

template <size_t N>
void solomon_sort(array<int, N> &arr, int n = N) {
	// min, max, delta
	int n_max = arr[0], n_min = arr[0];
	for (int i = 0, x; i < n; i++) {
		x = arr[i];
		n_max = max(n_max, x);
		n_min = min(n_min, x);
	}
	double d = double(n_max - n_min) / n;

	// distribution
	vector<int> indxs(n);
	vector<vector<int>> n_new(n);
	for (int i = 0, indx; i < n; i++) {
		indx = min(int((arr[i] - n_min) / d), n - 1);
		indxs[indx]++;
		n_new[indx].emplace_back(arr[i]);
	}

	// collection
	for (int i = 0, s = 0; i < n; i++) {
		while (indxs[i] != 0) {
			int m = 0;
			for (int j = 0; j < indxs[i]; j++) if (n_new[i][m] > n_new[i][j]) m = j;
			arr[s++] = n_new[i][m];
			n_new[i].erase(n_new[i].begin() + m);
			indxs[i]--;
		}
	}
}

int main() {
	array<int, 10> m{30, 55, 21, 17, 82, 46, 79, 63, 94, 108};
	for (int i : m) cout << i << " ";
	solomon_sort(m);
	cout << endl;
	for (int i : m) cout << i << " ";
}