#include <iostream>
#include <math.h>
using namespace std;

int main() {
	float x, a;
	cout << "Input x and a: ";
	cin >> x >> a;
	if (!cin) {
		cout << "Wrong input";
		return -1;
	}

	if (abs(x) < 1) {
		if (x != 0) {
			cout << (a * log(abs(x)));
		} else {
			cout << "Can't take natural logarithm of a zero";
		}
	} else {
		float w = a - x * x;
		if (w >= 0) {
			cout << (sqrt(w));
		} else {
			cout << "Can't take sqare root of a negative number";
		}
	}
}
