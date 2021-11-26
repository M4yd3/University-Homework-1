#include <iostream>
#include <math.h>
using namespace std;

int main() {
	cout << "Input M: ";
	int m; cin >> m;
	int t(m / 3), f(0);

	while (true) {
		int s = t * 3 + f * 4;
		if (s == m) {
			break;
		} else if (s > m) {
			t = 0;
			f = 0;
			break;
		} else {
			t = max(t - 1, 0);
			f++;
		}
	}

	cout << t << endl << f;
}