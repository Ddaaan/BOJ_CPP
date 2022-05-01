#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int check[20000001] = { 0, };
	int* card, * compare;
	int N, M, temp;
	
	cin >> N;
	card = new int[N];
	for (int i = 0; i < N; i++) cin >> card[i];
	cin >> M;
	compare = new int[M];
	for (int i = 0; i < M; i++) cin >> compare[i];
	
	for (int i = 0; i < N; i++) {
		temp = card[i] + 10000000;
		check[temp] += 1;
	}

	for (int i = 0; i < M; i++) {
		temp = compare[i] + 10000000;
		cout << check[temp] << ' ';
	}
	delete[]card;
	delete[]compare;
	return 0;
}