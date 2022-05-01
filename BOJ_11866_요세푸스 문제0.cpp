#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, count = 0, min = 0;
	queue <int> q;
	cin >> N >> K;
	cout << "<";
	for (int i = 1; i < N + 1; i++) q.push(i);
	while (N != min) {
		if (count == K-1) {
			if (min==N-1) cout << q.front();
			else cout << q.front() << "," << ' ';
			q.pop();
			count = 0;
			min++;
		}
		else {
			q.push(q.front());
			q.pop();
			count += 1;
		}
	}
	cout << ">";
	return 0;
}