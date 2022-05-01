#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, output = 0;
	string arr;
	cin >> num;
	for (int i = 0; i < 1000001; i++) {
		arr = to_string(i);
		output = i;
		for (int j = 0; j < arr.length(); j++) {
			output += ((int)arr[j] - 48);
		}
		if (num == output) {
			cout << i << "\n";
			break;
		}
		if (i == 1000000) cout << "0" << "\n";
	}
	return 0;
}