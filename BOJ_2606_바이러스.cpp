#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

void vir(int now, vvi virus, vector<bool>& check, int& count, int num) {
	check[now] = true;

	for (int i = 0; i < virus[now].size(); i++) {
		if (!check[virus[now	][i]]) {
			count++; //맨 처음 시작은 count하지 않음
			vir(virus[now][i], virus, check, count, num);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, pair, from, to, count = 0;
	vvi virus;
	vector<bool> check;
	cin >> num >> pair;

	virus.assign(num, vector<int>());
	check.assign(num, false);

	for (int i = 0; i < pair; i++) {
		cin >> from >> to;
		from--; to--;
		virus[from].emplace_back(to);
		virus[to].emplace_back(from);
	}

	vir(0, virus, check, count, num);
	cout << count << "\n";
	
	return 0;
}