#include <iostream>

using namespace std;

int gcd(int x, int y) {
	int temp;
	if (x < y) {
		temp = x;
		x = y;
		y = temp;
	}
	while (y != 0) {
		temp = x;
		x = y;
		y = temp % y;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M,num, a=0, b=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		a += num;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		b += num;
	}

}