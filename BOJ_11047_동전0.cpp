#include <iostream>
#include <algorithm>

using namespace std;
bool down(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, sum, * coin, count = 0;
	cin >> N >> sum;
	coin = new int[N]();
	for (int i = 0; i < N; i++)cin >> coin[i];
	sort(coin, coin + N, down);

	for (int i = 0; i < N; i++) {
		count += sum / coin[i];
		sum = sum % coin[i];
	}
	cout << count << "\n";
	delete[]coin;
	return 0;
}