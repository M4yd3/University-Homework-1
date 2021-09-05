#include <iostream>

using namespace std;

int main() {
	system("chcp 1251");
	cout << "Input two numbers: ";
	float a, b;
	cin >> a >> b;
	if (!cin) {
		cout << "Wrong input";
	} else {
		cout << a + b << endl;
		cout << a - b << endl;
		cout << a * b << endl;
		if (b != 0) {
			cout << a / b;
		} else {
			cout << "Can't divide by zero";
		}
	}

}