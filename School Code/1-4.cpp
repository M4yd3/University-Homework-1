#include <iostream>

using namespace std;

int main() {
	system("chcp 1251");
	cout << "Input three coefficients: ";
	float a, b, c;
	cin >> a >> b >> c;
	if (!cin) {
		cout << "Wrong input";
	} else {
		cout << "Answer: ";
		if (a == 0 && b != 0 && c != 0) {
			cout << (-c / b);
		} else if (a != 0 && b == 0 && c != 0) {
			float t = -c / a;
			if (t >= 0) {
				cout << sqrt(t) << " ";
				cout << -sqrt(t);
			} else {
				cout << "No roots";
			}
		} else if (a != 0 && b != 0 && c == 0) {
			cout << 0 << " ";
			cout << (-b / a);
		} else if (a == 0 && b == 0) {
			cout << "No roots";
		} else if ((a == 0 && b != 0 && c == 0) || (a != 0 && b == 0 && c == 0)) {
			cout << 0;
		} else {
			float d = b * b - (4 * a * c);
			if (d >= 0) {
				cout << (-b + sqrt(d)) / 2 / a << " ";
				cout << (-b - sqrt(d)) / 2 / a;
			} else {
				cout << "No roots";
			}
		}
	}
}