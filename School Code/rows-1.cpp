#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << "Input n";
	if (!cin) {
		cout << "Wrong input";
		return -1;
	}
	
	double divider = 0;
	double total = 0;
	for (int i = 1; i <= n; i++) {
		divider += sin(i);
		total += i / divider;
	}
	cout << "Answer: " << total << endl;
}