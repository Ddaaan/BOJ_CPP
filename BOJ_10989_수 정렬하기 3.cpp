#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num[10001] = { 0, }, temp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		num[temp] += 1;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < num[i]; j++) {
			cout << i << "\n";
		}
	}
	return 0;
}