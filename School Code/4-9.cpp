#include <iostream>
#include <string>
#include <regex>
#include <map>
using namespace std;

map<char, int> values = {{'0', 0},  {'1', 1},  {'2', 2},  {'3', 3},
                         {'4', 4},  {'5', 5},  {'6', 6},  {'7', 7},
                         {'8', 8},  {'9', 9},  {'A', 10}, {'B', 11},
                         {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};

string values_inverted = "0123456789ABCDEF";

bool is_valid(string number) {
  return regex_match(number, regex(R"(-?[0-9A-F]+(\.[0-9A-F]+)?)"));
}

int convert_before_dot(string number, int from) {
  int sum(0);
  for (int i = 0; i < number.size(); i++) {
    int n = values[number[i]];
    int m = (int)(n * pow(from, number.size() - i - 1));
    if (n >= from) {
        return -1;
    }
    sum += m;
  }
  return sum;
}

double convert_after_dot(string number, int from) {
    double sum(0);
    for (int i = number.size(); i > 0; i--) {
        int n = values[number[i - 1]];
        double m = n * pow(from, -i);
        if (n >= from) {
            return -1;
        }
        sum += m;
    }
    return sum;
}

string convert_integer_part_from_decimal(int number, int to) {
    string converted;
    while (number != 0) {
        converted = values_inverted[number % to] + converted;
        number /= to;
    }
    return converted;
}

string convert_float_part_from_decimal(double number, int to) {
    string converted(".");
    for (int i = 0; i < 7; i++) {
        number *= to;
        int n = (int)number;
        number -= n;
        converted += to_string(n);
    }
    if (values[converted[7]] > 4) {
        char t = converted[6];
        converted.resize(6);
        converted.shrink_to_fit();
        converted += values_inverted[values[t] + 1];
    }
    converted.resize(7);
    converted.shrink_to_fit();
    return converted;
}

string convert(string number, int from, int to) {
  if (to == from) {
    return number;
  }
  string converted("");

  double number_double(0);
  if (number.find("-") != -1) {
      number = number.substr(1, number.size() - 1);
      cout << number << endl;
      converted += "-";
  }
  
  string integer_part = number.substr(0, number.size());
  number_double += convert_before_dot(integer_part, from);
  if (number_double == -1) {
      return "Invalid input";
  }

  int dot = number.find(".");
  if (dot != -1) {
      integer_part = number.substr(0, dot);
      string float_part = number.substr(dot + 1, number.size());
      number_double += convert_after_dot(float_part, from);
  }

  converted += convert_integer_part_from_decimal((int)number_double, to);
  if (dot != -1) {
      converted += convert_float_part_from_decimal(number_double - (int)number_double, to);
  }
  return converted;
}

int main() {
  string number;
  int from, to;
  cout << "Input your number: ";
  cin >> number;
  cout << "Convert from: ";
  cin >> from;
  cout << "Convert to: ";
  cin >> to;

  if (!cin || from < 2 || from > 16 || to < 2 || to > 16 || !is_valid(number)) {
    cout << "Invalid input";
    return -1;
  }

  cout << convert(number, from, to);
}