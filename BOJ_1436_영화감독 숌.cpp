#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, count(0), input;
	cin >> input;
	int i = 665;
	while(1){
		num = i;
		while (num >= 666) {
			if (num % 1000 == 666) {
				count++;
				break;
			}
			else num /= 10;			
		}
		if (input == count) {
			cout << i << "\n";
			break;
		}
		i++;
	}
	return 0;
}