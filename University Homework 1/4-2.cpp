#include <iostream>
using namespace std;

int sign(double x) {
	if (x < 0) {
		return -1;
	}
	if (x == 0) {
		return 0;
	}
	return 1;
}

int main() {
	cout << "Input a number: ";
	double x;
	cin >> x;

	if (!cin) {
		cout << "Invalid input";
		return -1;
	}

	cout << sign(x);
}