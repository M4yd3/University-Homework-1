#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n = 5;
	cout << "Input N: ";
	cin >> n;
	if (!cin) {
		cout << "Wrong input";
		return -1;
	}
	
	n = max(1, n);

	cout << "Answer: ";
	for (int i = 0; i < 10; i++) {
		cout << (n + i) << " ";
	}
}
