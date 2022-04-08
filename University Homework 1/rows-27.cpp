#include <iostream>
#include <string>
using namespace std;

// 27
int main() {
	cout << "Input n: ";
	int n; cin >> n;

	if (!cin) {
		cout << "Invalid input";
		return -1;
	}

	if (to_string(n * n).find("3") != -1) {
		cout << "Yes";
	} else {
		cout << "No";
	}
}