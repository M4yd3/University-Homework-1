#include <iostream>
using namespace std;

int GetDividersSum(int n) {
	if (n <= 1) return 0;
	int ans = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans += i;
			if (n / i != i) ans += n / i;
		}
	}
	return ans;
}

int main() {
	int m, n; 
	cout << "Input limits";
	cin >> m >> n;
	if (!cin || n < 0 || m < 0) {
		cout << "Wrong input";
		return -1;
	}

	for (int i = m; i <= n; i++) {
		if (i == GetDividersSum(i)) {
			cout << i << " ";
		}
	}
}