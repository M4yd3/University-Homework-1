#include <iostream>
#include <string>
#include <regex>
#include <map>
using namespace std;

int main() {
  cout << "Input roman number: " << endl;
  string number;
  cin >> number;

  const regex r(
      R"(^(M{0,3})(D?C{0,3}|CM|CD)(L?X{0,3}|XC|XL)(V?I{0,3}|IX|IV)$)");
  if (!regex_match(number, r)) {
    cout << "Invalid input";
    return -1;
  }

  map<char, int> values = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                           {'C', 100}, {'D', 500}, {'M', 1000}};

  int sum(0);
  for (int i = 0; i < number.size(); i++) {
    sum += values[number[i]];
    if (i > 0 && values[number[i]] > values[number[i - 1]]) {
      sum -= 2 * values[number[i - 1]];
    }
  }
  cout << sum;
}
