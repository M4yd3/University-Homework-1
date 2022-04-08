#include <iostream>
#include <regex>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int _val) : val(_val), next(nullptr) {}
};

struct list {
	Node* first;
	Node* last;

	list() : first(nullptr), last(nullptr) {}

	bool is_empty() {
		return first == nullptr;
	}

	void push_back(int _val) {
		Node* p = new Node(_val);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	void print() {
		if (is_empty()) return;
		Node* p = first;
		while (p) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}

	void push_even_back() {
		if (is_empty()) return;
		Node* p = first;
		Node* l = last;
		while (p) {
			if (p->val % 2 == 0) push_back(p->val);
			if (p == l) break;
			p = p->next;
		}
	}
};

vector<string> split(const string& str) {
	const auto r = regex(" ");
	return vector<string>{
		sregex_token_iterator(cbegin(str), cend(str), r, -1),
			sregex_token_iterator()
	};
}

int main() {
	list l;
	string input;
	do {
		getline(cin, input);
		if (input.empty()) break;
		for (auto s : split(input)) {
			if (regex_match(s, regex(R"(\d+)"))) {
				l.push_back(stoi(s));
			}
			else {
				input.clear();
				break;
			}
		}
	} while (!input.empty());
	l.print();
	l.push_even_back();
	l.print();
}


