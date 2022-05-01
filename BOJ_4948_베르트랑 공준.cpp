#include <iostream>
#include <cmath>

using namespace std;

void prime_arr(int* flag) {
	int count(0);
	flag[0] = 1; flag[1] = 1;

	for (int i = 2; i <= 246912; i++) {
		if (flag[i] == 0) {
			for (int j = i + i; j <= 246912; j += i) flag[j] = 1;
		}
	}
}

int count(int* flag, int n) {
	int count(0);
	for (int i = n + 1; i <= 2 * n; i++) {
		if (flag[i] == 0) {
			count++;
		}
	}
	return count;
}

int main() {
	int num, output, flag[246913] = { 0, }, prime[246913];
	prime_arr(flag);
	while (1){
		cin >> num;
		if (!num) break;
		output = count(flag, num);
		cout << output << "\n";
	}
	return 0;
}