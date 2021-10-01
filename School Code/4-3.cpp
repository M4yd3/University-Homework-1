#include <iostream>
#include <algorithm>
using namespace std;

double rectangle_area(double r1, double r2) {
	return r1 * r2;
}

double triangle_area_1(double t1, double t2, double t3) {
	double p = (t1 + t2 + t3) / 2.0;
	return sqrt(p * (p - t1) * (p - t2) * (p - t3));
}

double triangle_area_2(double t1, double t2) {
    return t1 * t2 / 2;
}

double triangle_area_3(double t1, double t2, double t3) {
    return (t1 * t2 * sin(t3)) / 2.0;
}

double circle_area(double r) {
	const double PI = 3.141;
	return PI * powl(r, 2);
}

int main() {
  double r1, r2, t1, t2, t3(0), r;
  
  cout << "Input rectangle sides (2 values): ";
  cin >> r1 >> r2;
  if (!cin || r1 <= 0 || r2 <= 0) {
    cout << "Error: Impossible to calculate the area of the rectangle or "
            "invalid input"
         << endl;
  } else {
    cout << "The area of the rectangle is: " << rectangle_area(r1, r2) << endl;
  }

  int t;
  cout << "Choose a way to calculate triangle area:" << endl;
  cout << " 0 - with 3 sides" << endl;
  cout << " 1 - with height and base" << endl;
  cout << " 2 - with two sides and angle between them" << endl;
  cin >> t;
  if (!cin || t < 0 || t > 3) {
      cout << "Invalid input" << endl;
  }
  else {
      switch (t) {
      case 0:
          cout << "Input triangle sides (3 values): ";
          cin >> t1 >> t2 >> t3;
          break;
      case 1:
          cout << "Input triangle height and base (2 values): ";
          cin >> t1 >> t2;
          break;
      case 2:
          cout << "Input two triangle sides and angle between them (3 values): ";
          cin >> t1 >> t2 >> t3;
          break;
      }
      double m(max(t1, max(t2, t3)));
      if (!cin || t1 <= 0 || t2 <= 0 || t3 <= 0 || (t == 0 && m > t1 + t2 + t3 - m) || (t == 2 && t3 >= 180)) {
          cout << "Error: Impossible to calculate the area of the triangle or "
              "invalid input"
              << endl;
      }
      else {
          cout << "The area of the triangle is: ";
          switch (t) {
          case 0:
              cout << triangle_area_1(t1, t2, t3);
              break;
          case 1:
              cout << triangle_area_2(t1, t2);
              break;
          case 2:
              cout << triangle_area_3(t1, t2, t3);
              break;
          }
          cout << endl;
      }
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