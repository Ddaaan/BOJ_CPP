#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio (false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp, count = 0;
    vector <pair<int,int>> dot, ans; //dot 입력 배열 , ans 정답 출력 배열

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> temp;
        dot.emplace_back(temp, i); //인덱스 값을 함께 받아줌 //dot(입력 받은 좌표값, 인덱스 값)
    }
    sort(dot.begin(), dot.end()); //좌표값이 작은 순서대로 정렬

    ans.emplace_back(dot[0].second, 0); //정렬된 dot의 가장 처음값의 좌표압축은 0 //ans(초기 인덱스 값, 좌표압축 값)

    for (int i=1; i<n; i++){
        if (dot[i].first == dot[i-1].first) {
            ans.emplace_back(dot[i].second, count);
        }
        else {
            count += 1;
            ans.emplace_back(dot[i].second, count);
        }
    }

    sort(ans.begin(), ans.end()); //초기 인덱스 순서대로 정렬

    for (auto i:ans){
        cout << i.second << ' ';
    }
}