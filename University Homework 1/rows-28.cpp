#include <iostream>
using namespace std;

// 28
int main() {
	cout << "Input n: ";
	int n; cin >> n;
	n = abs(n);

	if (!cin) {
		cout << "Invalid input";
		return -1;
	}

	int s(0);
	while (n != 0) {
		s += n % 10;
		n /= 10;
	}
	cout << s;
}