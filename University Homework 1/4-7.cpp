#include <iostream>
#include <stack>
using namespace std;

int s_loop(int m, int i, int c) {
  struct Snapshot {
    int i;
    int stage;
  };

  int returnValue = 0;

  stack<Snapshot> steck;

  Snapshot currentSnapshot;
  currentSnapshot.i = i;
  currentSnapshot.stage = 0;

  steck.push(currentSnapshot);

  while (!steck.empty()) {
    currentSnapshot = steck.top();
    steck.pop();

    if (currentSnapshot.stage == 0) {
      if (currentSnapshot.i == 0) {
        returnValue = 0;
        continue;
      }
      currentSnapshot.stage = 1;
      steck.push(currentSnapshot);

      Snapshot newSnapshot;
      newSnapshot.i = currentSnapshot.i - 1;
      newSnapshot.stage = 0;
      steck.push(newSnapshot);
      continue;
    } else {
      returnValue = (m * returnValue + currentSnapshot.i - 1) % c;
      continue;
    }
  }

  return returnValue;
}

int main() {
  int m(37), i(3), c(64);
  cout << "m = " << m << ", i = " << i << ", c = " << c << endl;
  cout << s_loop(m, i, c) << endl;

  m = 25173;
  i = 13849;
  c = 65537;
  cout << "m = " << m << ", i = " << i << ", c = " << c << endl;
  cout << s_loop(m, i, c) << endl;
}