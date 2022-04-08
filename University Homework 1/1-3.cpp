#include <iostream>
using namespace std;

int main() {
	system("chcp 1251");
	cout << "Input two coefficients: ";
	float b, c;
	cin >> b >> c;
	if (!cin) {
		cout << "Wrong input";
	} else {
		cout << "Answer: ";
		if (b != 0) {
			cout << (-c / b);
		} else {
			cout << "Can't divide by zero";
		}
	}
}