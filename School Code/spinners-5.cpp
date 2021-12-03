#include <iostream>
#include <vector>
using namespace std;

int main() {
	long n, k; cin >> n >> k;
	vector<long> seats{ n };

	long l, r;
	for (long i = 0, m; i < k; i++) {
		m = 0;
		for (long j = 1; j < size(seats); j++) if (seats[m] < seats[j]) m = j;
		r = seats[m] / 2;
		l = seats[m] - 1 - seats[m] / 2;
		seats.erase(seats.begin() + m);
		if (r != 0) seats.insert(seats.begin() + m, r);
		if (l != 0) seats.insert(seats.begin() + m, l);
	}

	cout << l << endl << r;
}