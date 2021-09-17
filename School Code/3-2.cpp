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
	int min_p = 0;
	float min_diff = FLT_MAX;
	for (float i = 0; i <= 100; i++) {
		float r = i / 100;
		float k = powf(1 + r, n);
		float result = ((S * r * k) / (12 * (k - 1)));
		float diff = abs(result - m);
		if (min_diff > diff) {
			min_p = i;
			min_diff = diff;
		}
	}
	cout << min_p;
}
