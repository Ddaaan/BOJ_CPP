#include <iostream>

using std::cin;
using std::cout;

int main() {
	int score, total = 0;
	for (int i = 0; i < 5; i++) {
		cin >> score;
		total += score;
	}
	cout << total << "\n";
	return 0;
}