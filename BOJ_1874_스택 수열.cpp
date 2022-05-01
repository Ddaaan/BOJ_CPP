#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> s;
	string ans;
	int n, num, temp = 1, flag = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (s.empty() == 0 && s.top() == num) { //스택의 맨 위 숫자가 num과 같으면 제거 후 -출력
			s.pop();
			ans.append("-");
		}
		else {
			for (int j = temp; j <= num; j++) { //if구문이 아니면 스택에 num까지의 수를 차곡차곡 채워줌
				s.push(j);
				ans.append("+"); //한 번 채울때마다 +출력해주기
			}
			if (s.top() == num) { //스택의 맨 위 숫자가 num과 같으면 제거해주고 -출력
				s.pop();
				ans.append("-");
			}
			else { //스택의 맨 위 숫자가 num과 다르면 입력받은 수열을 만들수 없다는 뜻임
				cout << "NO" << "\n"; 
				flag = 1; //나중에 가능할 경우를 출력해주기 위해서 flag로 불가능한 수열이라는걸 표시해주기
				break;
			}
			temp = num + 1; //temp는 지금 어디까지의 수가 스택에 넣어졌는지 -> 그 다음 숫자부터 스택에 넣어주어야함
		}
	}

	if (flag == 0) { //입력받은 수열이 만들어지면 -> 문자열 출력
		for (int i = 0; i < ans.length(); i++) cout << ans[i] << "\n";
	}
	return 0;
}