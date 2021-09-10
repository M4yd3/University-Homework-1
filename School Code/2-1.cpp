#include <iostream>
using namespace std;

int main() {
	float PI = 3.14159265358979323846;
	float R, r, h, l;
	cout << "Input radius of lower base: ";
	cin >> R;
	cout << "Input radius of upper base: ";
	cin >> r;
	cout << "Input the height of the cone: ";
	cin >> h;
	cout << "Input the slant of the cone: ";
	cin >> l;
	if (!cin || R <= 0 || r <= 0 || h <= 0 || l <= 0) {
		cout << "Wrong input";
		return -1;
	}

	cout << "Cone volume: " << ((PI * h * (R*R + R*r + r*r)) / 3);
	cout << "Cone surface area: " << (PI * (R*R + (R + r) * l + r*r));
}
