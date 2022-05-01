#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, a = 0, b = 0, count = 0;
	string bracket;
	cin >> T;

	for (int i = 0; i < T; i++) {
		a = 0, b = 0, count = 0;
		cin >> bracket;

		for (int j = 0; j < bracket.length(); j++) {
			if (bracket[j] == '(') count+=1, a+=1; //count는 (와 )가 짝을 이루나 판별 -> 음수가 나오면 짝이 틀린거
			else if (bracket[j] == ')') count-=1, b+=1; //(의 개수와 )개수도 따로 세어줌

			if (count < 0) {
				cout << "NO" << "\n";
				break;
			}
		}

		if (count >= 0 && a == b) cout << "YES" << "\n";
		else if (count >= 0 && a != b) cout << "NO" << "\n";
	}
	return 0;
}