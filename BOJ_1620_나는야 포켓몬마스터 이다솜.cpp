#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map <int, string> pocket_num;
	map <string, int> pocket_str;
	string str, tempStr;
	int tempNum;
	int n, m;
	cin >> n >> m;

	for (int i =1; i <= n; i++) {
		cin >> str;
		pocket_num.insert(make_pair(i, str)); //���ڸ� �Է¹޾��� �� ����� map
		pocket_str.insert(make_pair(str, i)); //���ڸ� �Է¹޾��� �� ����� map
	}
	for (int i = 0; i < m; i++) {
		cin >> tempStr;
		if ((int)tempStr[0] < 60) { //�Է¹��� ���� �����̸�
			tempNum = stoi(tempStr); //���ڿ��� ������ �ٲ� �������� ��
			cout << pocket_num[tempNum] << "\n"; //�˸��� value�� ã���ش�
		}
		else cout << pocket_str[tempStr] << "\n";
	}
	return 0;
}