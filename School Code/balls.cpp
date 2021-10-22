#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> v) {
    for (int i = 0; i < v.size(); i++) if (v[i] == i) return true;
    return false;
}

int main()
{
    cout << "Input the amount of balls in the bin: ";
    int n; cin >> n;
    
    if (!cin || n <= 0) {
        cout << "Invalid input";
        return -1;
    }

    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(i);

    int c(0);
    cout << "Calculating..." << endl;
    do {
        if (check(v)) c++;
    } while (next_permutation(v.begin(), v.end()));
    cout << "Answer: " << c;
}