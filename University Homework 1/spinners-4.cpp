#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int coupe_num(int n) {
	if (n < 36) return (n - 1) / 4;
	return (n - 37) / 2;
}

set<int> get_coupe_seats(int n) {
	return {n * 4 + 1, n * 4 + 2, n * 4 + 3, n * 4 + 4, 54 - n * 2, 53 - n * 2};
}

int main() {
	int n; cin >> n;
	
	if (n < 6) {
		cout << 0;
		return -1;
	}

	int coupes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	set<int> free_seats = set<int>();

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		free_seats.insert(x);
	}
	
	for (int i : free_seats) {
		int c = coupe_num(i);
		if (coupes[i] == 0) {
			for (int k : get_coupe_seats(c)) {
				if (free_seats.find(k) == free_seats.end()) {
					coupes[c] = -1;
					break;
				}
			}
			if (coupes[c] != -1) {
				coupes[c] = 1;
			}
		}
	}

	int m = 0, c;
	for (int i : coupes) {
		if (i == 1) {
			c++;
		} else {
			m = max(m, c);
			c = 0;
		}
	}

	cout << m;
}