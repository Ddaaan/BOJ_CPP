#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int money, num;
	cin >> money >> num;
	cout << money / num << "\n";
	cout << money % num << "\n";
	return 0;
}