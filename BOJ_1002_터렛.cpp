#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, x1, x2, y1, y2, r1, r2, R_plus, R_min;
	double dis;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		dis = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		R_plus = r1 + r2;
		R_min = abs(r1 - r2);

		if (dis==0&&r1 == r2) cout << "-1" << "\n";
		else if (R_plus == dis || R_min == dis) cout << "1" << "\n";
		else if (R_min < dis && dis < R_plus) cout << "2" << "\n";
		else cout << "0" << "\n";
	}
	
	return 0;
}