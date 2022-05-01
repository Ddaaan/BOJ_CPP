#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, count=0, length;
    string str;
    bool flag;
    cin >> n;

    while(n--) {
        cin >> str;
        length = str.size();
        flag = true;

        for (int i=0; i<length; i++) {
            for (int j=0; j<i; j++) {
                if (str[i]!=str[i-1] && str[i]==str[j]) { //그룹단어가 아닐때 flag를 false로
                    flag = false;
                    break;
                }
            }
        }
        if (flag == true) count++;
    }
    cout << count << "\n";
    
    return 0;
}