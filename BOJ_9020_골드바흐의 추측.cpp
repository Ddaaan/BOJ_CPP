#include <iostream>
#include <cmath>

using namespace std;

void eratos(int* flag, int n, int* prime) { //소수 판별 함수
	int count = 0;
	flag[0] = 1; flag[1] = 1;
	for (int i = 2; i <= sqrt(n); i++) {
		if (flag[i] == 0) {
			for (int j = i + i; j < n + 1; j += i) flag[j] = 1;
		}
	}
}

int prime_len(int n, int *flag, int *prime) {
	int count = 0;
	for (int i = 2; i < n + 1; i++) {
		if (flag[i] == 0) {
			prime[count] = i;
			count++;
		}
	}
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, num, len, a = 0, b = 0, min = 10e8, sub;
	int flag[10001] = { 0, }, prime[10000];
	cin >> T;
	eratos(flag, 10000, prime);

	for (int i = 0; i < T; i++) {
		min = 10e8;
		cin >> num;
		len = prime_len(num, flag, prime);

		for (int k = 0; k < len; k++) {
			for (int j = 0; j < len; j++) {
				if (prime[k] + prime[j] == num) {
					sub = abs(prime[k] - prime[j]);
					if (sub < min) {
						min = sub;
						a = prime[k];
						b = prime[j];
					}
				}
			}
		}
		if (a < b) cout << a << ' ' << b << "\n";
		else cout << b << ' ' << b << "\n";
	}
	return 0;
}