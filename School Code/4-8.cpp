#include <iostream>
#include <string>
using namespace std;

int main() {
  double a[3][4];
  double b[4][2];
  double c[3][2];

  cout << "Input matrix a: " << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> a[i][j];
    }
  }

  cout << "Input matrix b: " << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> b[i][j];
    }
  }
  

  for (int i = 0; i < 3; i++) {
    for (int k = 0; k < 2; k++) {
      double sum(0);
      for (int j = 0; j < 4; j++) {
        sum += a[i][j] * b[j][k];
      }
      c[i][k] = sum;
    }
  }

  cout << endl << "Resulting matrix:" << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      string value = to_string(c[i][j]);
      value.resize(5, ' ');
      value.shrink_to_fit();
      cout << value << " ";
    }
    cout << endl;
  }
  cout << endl;

  // 1
  int mx(0), mn(0);
  for (int i = 0; i < 3; i++) {
    if (c[mx][0] < c[i][0]) {
      mx = i;
    }
    if (c[mn][0] > c[i][0]) {
      mn = i;
    }
  }
  cout << "Max profit: " << c[mx][0] << endl;
  cout << "Min profit: " << c[mn][0] << endl << endl;

  // 2
  mx = 0;
  mn = 0;
  for (int i = 0; i < 3; i++) {
    if (c[mx][1] < c[i][1]) {
      mx = i;
    }
    if (c[mn][1] > c[i][1]) {
      mn = i;
    }
  }
  cout << "Max commission: " << c[mx][1] << endl;
  cout << "Min commission: " << c[mn][1] << endl << endl;


  // 3
  int tp(0);
  for (int i = 0; i < 3; i++) {
    tp += c[i][0];
  }
  cout << "Total profit: " << tp << endl << endl;

  // 4
  int tc(0);
  for (int i = 0; i < 3; i++) {
    tc += c[i][1];
  }
  cout << "Total commission: " << tc << endl << endl;

  // 5
  cout << "Total money: " << tp + tc << endl;
}
