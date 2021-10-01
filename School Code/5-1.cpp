#include <iostream>
using namespace std;

int nod_div(int a, int b) {
	while (a > 0 && b > 0) {
		if (a > b) a %= b;
		else b %= a;
	}
	return a + b;
}

int nod_sub(int a, int b) {
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}

int main() {
	int a, b;
	cout << "Input 2 numbers: ";
	cin >> a >> b;
	
	if (!cin || a <= 0 || b <= 0) {
		cout << "Invaid input";
		return -1;
	}

	cout << "Biggest common divider with division: " << nod_div(a, b) << endl;
	cout << "Biggest common divider with substraction: " << nod_sub(a, b) << endl;
}
