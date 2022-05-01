#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

void war(int x, int y, vvc soldier, vvb& check, int &count, int n, int m, char color) {
	int nx, ny;
	count++;
	
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (soldier[nx][ny] == color && !check[nx][ny]) {
				check[nx][ny] = true;
				war(nx, ny, soldier, check, count, n, m, color);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, count = 0;
	string str;
	vvc soldier;
	vvb check;
	vector <int> ans;
	int white=0, black=0;

	cin >> m >> n;
	soldier.assign(n, vector<char>(m));
	check.assign(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			soldier[i][j] = str[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <m; j++) {
			if (!check[i][j]) {
				count = 0;
				check[i][j] = true;
				if (soldier[i][j] == 'W') {
					war(i, j, soldier, check, count, n, m, 'W');
					white += (count * count);
				}
				else {
					war(i, j, soldier, check, count, n,m, 'B');
					black += (count*count);
				}
			}
		}
	}

	cout << white << ' ' << black << "\n";

	return 0;
}