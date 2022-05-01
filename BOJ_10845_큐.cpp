#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue <int> q;
	string cmd;
	int N, num;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> num;
			q.push(num);
		}

		else if (cmd == "pop") {
			if (q.empty()) cout << "-1" << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}

		else if (cmd == "front") {
			if (q.empty()) cout << "-1"<<"\n";
			else	cout << q.front() << "\n";
		}

		else if (cmd == "back") {
			if (q.empty()) cout << "-1" << "\n";
			else cout << q.back()<<"\n";
		}

		else if (cmd == "size") {
			cout << q.size()<<"\n";
		}

		else if (cmd == "empty") {
			cout << q.empty() << "\n";
		}
	}
	return 0;
}