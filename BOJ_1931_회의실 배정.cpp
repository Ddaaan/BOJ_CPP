#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, temp = 0, count = 1, a, b;
	vector<pair <int, int>> time;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		time.push_back(make_pair(b, a));
	}
	sort(time.begin(), time.end());

	temp = time[0].first;
	for (int i = 1; i < n; i++) {
		if (temp <= time[i].second) {
			temp = time[i].first;
			count++;
		}
	}
	cout << count << "\n";

	return 0;
}