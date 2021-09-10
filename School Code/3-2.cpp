#include <iostream>
using namespace std;

int main() {
	float S, m, n;
	cout << "Input loan amount: ";
	cin >> S;
	cout << "Input loan monthly payment: ";
	cin >> m;
	cout << "Input loan term in years: ";
	cin >> n;
	if (!cin || S <= 0 || m <= 0 || n <= 0) {
		cout << "Wrong input";
		return -1;
	}
	float k = S / (12 * n);
	cout << "Loan interest: " << (((m - k) / k) * 100);
}
