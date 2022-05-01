#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

const int dx[8] = { 0,0,1,-1 ,-1,-1,1,1 };
const int dy[8] = { 1,-1,0,0,-1,1,-1,1 };

void island(int x, int y, vvi map, vvb& check, int width, int height) {
	int nx, ny;

	for (int i = 0; i < 8; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 0 && nx < height && ny >= 0 && ny < width) {
			if (map[nx][ny] && !check[nx][ny]) {
				check[nx][ny] = true;
				island(nx,ny, map, check, width, height);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int width, height, ans = 0;
	vvi map;
	vvb check;

	while (1) {
		cin >> width >> height;
		if (width == 0 && height == 0) break;
		map.assign(height, vector<int>(width));
		check.assign(height, vector<bool>(width, false));

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (!check[i][j] && map[i][j]) {
					check[i][j] = true;
					island(i,j, map, check, width, height);
					ans++;
				}
			}
		}
		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}