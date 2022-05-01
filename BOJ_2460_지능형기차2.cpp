#include<iostream>

using std::cin;
using std::cout;

int main() {
	int in, out, total = 0, max = 0;
	for (int i = 0; i < 10; i++) {
		cin >> out >> in;
		total = total + in - out;
		if (total > max)max = total;
	}
	cout << max << "\n";
	return 0;
}