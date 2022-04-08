#include <iostream>
using namespace std;

bool is_prime(int n) {
	for (int i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
	return true;
}

int main() {
	int n;
	cout << "Input a number: ";
	cin >> n;

	if (!cin || n <= 2) {
		cout << "Invaid input";
		return -1;
	}
	for (int i = 3; i < n; i += 2) {
		if (is_prime(i)) cout << i << endl;
	}
}
