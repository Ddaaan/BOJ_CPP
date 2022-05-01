#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> num;
	int n, target, temp;
	cin >> n >> target;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		num.emplace_back(temp);
	}
	sort(num.begin(), num.end());
	cout << num[target - 1];
	return 0;
}