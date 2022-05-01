#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <vector<int>> vi;
typedef vector <vector<bool>> vb;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void apt(int x, int y, int size, vi table, vb& check, int& count) {
	int nx, ny;
	count++;

	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
			if (table[nx][ny] && !check[nx][ny]) {
				check[nx][ny] = true;
				apt(nx, ny, size, table, check, count);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size, count = 0;
	string str;
	vector<int> ans;
	vi table;
	vb check;

	cin >> size;
	table.assign(size, vector<int>(size));
	check.assign(size, vector <bool>(size, false));

	for (int i = 0; i < size; i++) {
		cin >> str;
		for (int j = 0; j < size; j++) {
			table[i][j] = (int)str[j] - 48;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (table[i][j] && !check[i][j]) {
				check[i][j] = true; //시작점도 체크해주기
				count = 0;
				apt(i, j, size, table, check, count);
				ans.emplace_back(count);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";

	return 0;
}