#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<int> s;
	string cmd;
	int n, num;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> num;
			if (s.count(num) == 0)	s.insert(num);
		}
		else if (cmd == "remove") {
			cin >> num;
			if (s.count(num) != 0) s.erase(num);
		}
		else if (cmd == "check") {
			cin >> num;
			cout << s.count(num) << "\n";
		}
		else if (cmd == "toggle") {
			cin >> num;
			if (s.count(num) != 0) s.erase(num);
			else s.insert(num);
		}
		else if (cmd == "all") {
			for (int i = 1; i < 21; i++) s.insert(i);
		}
		else if (cmd == "empty") {
			s.clear();
		}
	}
	return 0;
}