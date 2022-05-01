#include <iostream>
#include <algorithm>

using namespace std;

void binarySearch(int n, int target, int *arr) {
	int start = 0, end = n-1, mid;

	while (start <= end) {
		mid = (start + end) / 2;

		if (arr[mid] == target) {
			cout << "1" << "\n";
			return;
		}
		else if (arr[mid] >= target) end = mid - 1;
		else 	start = mid + 1;
	}
	cout << "0" << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, * arr, M, num;
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		binarySearch(N, num, arr);
	}
	return 0;
}