#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, count = 0;
	cin >> n;
	
	for (int i = 5; i <= n; i*=5) {
		count += n / i;
	}

	cout << count << "\n";
	return 0;
}