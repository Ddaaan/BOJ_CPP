#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string num;
	cin >> num;

	sort(num.begin(), num.end(), greater<char>());
	cout<<num;

	return 0;
}