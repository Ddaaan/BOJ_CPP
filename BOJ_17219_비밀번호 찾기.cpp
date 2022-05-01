#include <iostream>
#include <map>	

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, string> save;
	int n, m;
	string site, pw;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> site >> pw;
		save[site] = pw;
	}
	for (int i = 0; i < m; i++) {
		cin >> site;
		cout << save[site] << "\n";
	}
	return 0;
}