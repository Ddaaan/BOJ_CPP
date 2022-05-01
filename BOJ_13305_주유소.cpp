#include <iostream>

using namespace std;

int main() {
	int N, * dis, * price, min = 10e8, total = 0, fee = 0, km = 0;
	cin >> N;
	dis = new int[N-1];
	price = new int[N];
	for (int i = 0; i < N - 1; i++) {
		cin >> dis[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}
	fee += dis[0] * price[0];

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (price[i] < price[j]) km += dis[j-1];
		}
		fee += km * price[i];
	}

	cout << total << "\n";
	delete dis;
	delete price;
	return 0;
}