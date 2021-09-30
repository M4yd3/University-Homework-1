#include <iostream>
#include <string>
#include <regex>
#include <map>
using namespace std;

map<char, int> values = {{'0', 0},  {'1', 1},  {'2', 2},  {'3', 3},
                         {'4', 4},  {'5', 5},  {'6', 6},  {'7', 7},
                         {'8', 8},  {'9', 9},  {'A', 10}, {'B', 11},
                         {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};

map<int, char> values_inverted = {
    {0, '0'},  {1, '1'},  {2, '2'},  {3, '3'},  {4, '4'},  {5, '5'},
    {6, '6'},  {7, '7'},  {8, '8'},  {9, '9'},  {10, 'A'}, {11, 'B'},
    {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'},
};

bool is_valid(string number) {
  return regex_match(number, regex(R"([0-9A-F]+)"));
}

int convert_to_decimal(string number, int from) {
  int sum(0);
  for (int i = 0; i < number.size(); i++) {
    sum += (int)(values[number[i]] * pow(from, number.size() - i - 1));
  }
  return sum;
}

string convert_from_decimal(int number, int to) {
  string converted;
  while (number != 0) {
    converted = values_inverted[number % to] + converted;
    number /= to;
  }
  return converted;
}

string convert(string number, int from, int to) {
  if (to == from) {
    return number;
  }
  int number_decimal = convert_to_decimal(number, from);
  string converted = convert_from_decimal(number_decimal, to);
  return converted;
}

int main() {
  string number;
  int from(10), to(2);
  cout << "Input your number: ";
  cin >> number;
  cout << "Convert from: ";
  cin >> from;
  cout << "Convert to: ";
  cin >> to;

  if (!cin || from < 2 || from > 16 || to < 2 || to > 16 || !is_valid(number)) {
    cout << "Wrong input";
    return -1;
  }

  cout << convert(number, from, to);
}