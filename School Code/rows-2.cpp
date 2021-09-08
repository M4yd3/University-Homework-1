#include <iostream>
#include <list>

using namespace std;

int factorial(int n) {
	if (n <= 2) return n;
	return factorial(n - 1) * n;
}

int main() {
	int n = 5; 
	cin >> n;
	if (!cin || n < 0) {
		cout << "Wrong input";
		return -1;
	}

	int numerator = factorial(n);
	int d = 0;
	float ans = 0;

	for (int i = n; i > 0; i--) {
		int k = n - i + 1;
		int divider = ((1 + d + k) * (d + k) / 2) - ((1 + d) * d / 2);
		ans += numerator / sqrt(divider);
		numerator /= i;
		d += k;
	}
	cout << "Answer: " << ans;
}