#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string sentance;
	int small = 0, big = 0, flag = 0;
	getline(cin, sentance);

	while (1) {
		if (sentance.length() == 1 && sentance[0] == '.') break;
		small = 0, big = 0;
		cin >> sentance;
		
		for (int i = 0; i < sentance.length(); i++) {
			if (sentance[i] == '(') small += 1;
			else if (sentance[i] == ')') small -= 1;
			else if (sentance[i] == '[') big += 1;
			else if (sentance[i] == ']') big -= 1;

			if (small < 0 || big < 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0 && small == 0 && big == 0) cout << "yes" << "\n";
		else 	cout << "no" << "\n";
	}
	return 0;
}