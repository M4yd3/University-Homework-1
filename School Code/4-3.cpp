#include <iostream>
#include <algorithm>
using namespace std;

double rectangle_area(double r1, double r2) {
	return r1 * r2;
}

double triangle_area(double t1, double t2, double t3) {
	double p = (t1 + t2 + t3) / 2.0;
	return sqrt(p * (p - t1) * (p - t2) * (p - t3));
}

double circle_area(double r) {
	const double PI = 3.141;
	return PI * powl(r, 2);
}

int main() {
  double r1, r2, t1, t2, t3, r;
  
  cout << "Input rectangle sides (2 values): ";
  cin >> r1 >> r2;
  if (!cin || r1 <= 0 || r2 <= 0) {
    cout << "Error: Impossible to calculate the area of the rectangle or "
            "invalid input"
         << endl;
  } else {
    cout << "The area of the rectangle is: " << rectangle_area(r1, r2) << endl;
  }

  cout << "Input triangle sides (3 values): ";
  cin >> t1 >> t2 >> t3;
  double m(max(t1, max(t2, t3)));
  if (!cin || t1 <= 0 || t2 <= 0 || t3 <= 0 || m > t1 + t2 + t3 - m) {
    cout << "Error: Impossible to calculate the area of the triangle or "
            "invalid input"
         << endl;
  } else {
    cout << "The area of the triangle is: " << triangle_area(t1, t2, t3)
         << endl;
  }

  cout << "Input circle radius (1 value): ";
  cin >> r;
  if (!cin || r <= 0) {
    cout << "Error: Impossible to calculate the area of the circle or invalid "
            "input"
         << endl;
  } else {
    cout << "The area of the circle is: " << circle_area(r) << endl;
  }
}