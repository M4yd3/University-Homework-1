#include <iostream>
using namespace std;

int main() {
	float S, r, n;
	cout << "Input loan amount: ";
	cin >> S;
	cout << "Input loan monthly interest: ";
	cin >> r;
	r /= 100;
	cout << "Input loan term in years: ";
	cin >> n;
	if (!cin || S <= 0 || r < 0 || n <= 0) {
		cout << "Wrong input";
		return -1;
	}
	cout << "Monthly payment: ";
	if (r == 0) {
		cout << (S / (n * 12));
		return -1;
	}

	float k = powf(1 + r, n);
	cout << ((S * r * k) / (12 * (k - 1)));
}
