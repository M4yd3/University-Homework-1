#include <iostream>
#include <math.h>
using namespace std;

int main() {
	float x, y, b;
	cout << "Input x, y and b: ";
	cin >> x >> y >> b;
	if (!cin || b - y <= 0 || b - x < 0) {
		cout << "Wrong input or impossible calculations";
		return -1;
	}

	cout << "Answer: " << (log(b - y) * sqrt(b - x));
}
