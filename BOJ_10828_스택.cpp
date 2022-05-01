#include <iostream>
#include <stack>
#include <string>	

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack <int> s;
	string cmd;
	int N, num;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> num;
			s.push(num);
		}
		else if (cmd == "pop") {
			if (s.empty()) cout << "-1" << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (cmd == "size") {
			cout << s.size() << "\n";
		}
		else if (cmd == "empty") {
			cout << s.empty() << "\n";
		}
		else if (cmd == "top") {
			if (s.empty()) cout << "-1" << "\n";
			else cout << s.top() << "\n";
		}
	}
	return 0;
}