#include <iostream>

using std::cin;
using std::cout;

int main() {
	int young=0, min=0,N, call, temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> call;
		temp = (call / 30) + 1;
		young += temp * 10;
		temp = (call / 60) + 1;
		min += temp * 15;
	}
	if (young < min) {
		cout << "Y " << young << "\n";
	}
	else if (min < young) {
		cout << "M " << min << "\n";
	}
	else {
		cout << "Y " << "M " << min << "\n";
	}
}