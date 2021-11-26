#include <iostream>
using namespace std;

int main() {
	long n, m; cin >> n >> m;
	long c = ((n + 1) * n / 2) * ((m + 1) * m / 2);
	cout << c;
}