#include <iostream>
#include <stack>	

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, sum = 0, num;
	stack <int> s;

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> num;
		if (num == 0) {
			sum -= s.top();
			s.pop();
		}
		else {
			s.push(num);
			sum += s.top();
		}
	}

	cout << sum << "\n";
	return 0;
}