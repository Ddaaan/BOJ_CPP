#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, int> people;
	vector <string> ans;
	int n, m, count = 0;
	string temp;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		people[temp]++; //map에 입력받으면서 value값을 체크해줌
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (people[temp]) { //입력받은 key값이 체크가 되어있으면
			count++; 
			ans.emplace_back(temp); //ans배열에 넣어줌 (중복되어 나왔다는 이야기)
		}
	}
	sort(ans.begin(), ans.end()); //오름차순으로 출력해야하기 때문에 정렬 해주기

	cout << count << "\n";
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
	return 0;
}