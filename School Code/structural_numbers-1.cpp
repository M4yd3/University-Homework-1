#include <iostream>
#include <string> 
#include <set>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	if (!cin) {
		cout << "Wrong input";
		return -1;
	}

	set<string> ans;
	for (int i = m; i < n; i++) {
		for (int k = i + 1; k <= n; k++) {
			int x = k * k - i * i;
			int y = 2 * k * i;
			int z = k * k + i * i;
			
			int t = min(x, y);
			y = max(x, y);
			x = t;

			int xs = x, ys = y, zs = z;

			int j = 1;
			while (z * j <= n) {
				string str = to_string(x * j) + " " + to_string(y * j) + " " + to_string(z * j);
				ans.insert(str);
				cout << j << " " << z * j << " " << n << endl;
				j++;
			}
		}
	}
	for (string row : ans) {
		cout << row << endl;
	}
}