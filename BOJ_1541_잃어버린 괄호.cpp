#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string arr, temp;
    bool min = false;
    int length, total = 0, count = 0;
    cin >> arr;
    length = arr.size();

    for (int i = 0; i < length; i++) {
        if (isdigit(arr[i])) {
            temp += arr[i];
        }

        else {
            if (count==0) {
                total += stoi(temp);
                temp.clear();
                count++;
                if (arr[i] == '-') min = true;
                continue;
            }

            if (min) {
                total -= stoi(temp);
                temp.clear();
            }
            else {
                total += stoi(temp);
                temp.clear();
            }

            if (arr[i] == '-') {
                min = true;
            }
        }
    }

    if (min) {
        total -= stoi(temp);
        temp.clear();
    }
    else {
        total += stoi(temp);
        temp.clear();
    }

    cout << total << "\n";
    return 0;
}