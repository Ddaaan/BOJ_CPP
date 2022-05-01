#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector <vector<int>> vvi;

void dfs(int now, vvi table, vector<bool>& check) {
	cout << now + 1 << ' ';
	check[now] = true;

	for (int i = 0; i < table[now].size(); i++) {
		if (!check[table[now][i]]) {
			dfs(table[now][i], table, check);
		}
	}
}

void bfs(int start, vvi table, vector<bool>& check) {
	int temp;
	queue <int> q;

	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		temp = q.front();
		q.pop();
		cout << temp + 1 << " ";

		for (int i = 0; i < table[temp].size(); i++) {
			if (!check[table[temp][i]]) {
				check[table[temp][i]] = true;
				q.push(table[temp][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int point, line, start;
	int from, to;
	vvi table;
	vector<bool> check;

	cin >> point >> line >> start;
	start--;
	table.assign(point, vector<int>());
	check.assign(point, false);
	
	for (int i = 0; i < line; i++) { //�Է� 
		cin >> from >> to;
		from--; to--;
		table[from].emplace_back(to);
		table[to].emplace_back(from);
	}

	for (int i = 0; i < point; i++) {
		sort(table[i].begin(), table[i].end());
	}

	dfs(start, table, check);
	cout << "\n";

	check.assign(point, false); //üũ�迭 �ʱ�ȭ �����ֱ�
	bfs(start, table, check);

	return 0;
}