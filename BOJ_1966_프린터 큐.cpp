#include <iostream>
#include <queue>	

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, num, t, count = 0;
	queue <int> importance, document;
	priority_queue <int> temp;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		count = 0;

		for (int i = 0; i < n; i++) {
			cin >> num;
			importance.push(num); //중요도 순서대로 저장
			temp.push(num); //우선순위 큐에 num입력
			document.push(i); //문서 순서 입력 0부터 차례로
		}

		while (1) {
			if (temp.top() == importance.front()) { //가장 높은 중요도와 importance.front가 같으면
				if (m == document.front()) { //m이랑 문서 순서가 같으면
					cout << count + 1 << "\n"; //출력하고 break
					//남은 큐 초기화
					while (!importance.empty()) importance.pop();
					while (!temp.empty()) temp.pop();
					while (!document.empty()) document.pop();
					break;
				}
				importance.pop(); //중요도 앞에서 제거
				document.pop(); //문서순서 앞에서 제거
				temp.pop(); //가장 높은 수 제거
				count++;
			}
			else {
				importance.push(importance.front()); //맨 앞에 있는 중요도 맨 뒤로 보내기
				document.push(document.front()); //맨 앞에 있는 문서 맨 뒤로 보내기
				importance.pop(); //보낸 중요도 앞에서 없애기
				document.pop(); //보낸 문서 맨 앞에서 없애기
			}
		}
	}
	return 0;
}