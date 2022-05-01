#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    bool flag = true;
    int t, count = 0, length, temp;
    int arr[26] = {0, };

    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> str;
        length = str.size();
        for (int j=0; j<length-2; j++) {
            if (str[i]!=str[i+1]) {
                for (int k=i+2; k<length; k++) {
                    if (str[j] == str[i]){
                        break;
                    }
                }
            }
        }
        count++;
    }
    return 0;
}