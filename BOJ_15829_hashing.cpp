#include <iostream>
#include <string>

using namespace std;

const int M = 1234567891;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long len, H = 0, R = 1;
	string str;
	cin >> len >> str;

	for (int i = 0; i < len; i++) {
		H = ((H + (str[i] - 'a' + 1) * R) % M)%M;
		R = (R * 31) % M;
	}
	cout << H << "\n";
	return 0;
}