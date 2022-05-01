#include <iostream>

using namespace std;

void sum(long long int* sum_arr) {
	sum_arr[1] = 1;
	for (int i = 2; i < 1000001; i++) {
		for (int j = 1; i * j < 1000001; j++) {
			sum_arr[i * j] += i;
		}
		sum_arr[i] += (sum_arr[i - 1]+1); //1은 반복에서 고려 안했으나 모든 수의 약수이므로 더해줌
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, num;
	long long sum_arr[1000001] = { 0, };
	sum(sum_arr);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> num;
		cout << sum_arr[num] << "\n";
	}
	return 0;
}