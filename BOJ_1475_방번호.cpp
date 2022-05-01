#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int length, count=0;
    double temp;
    string input;
    vector <int> num(9, 0);

    cin >> input;
    length = input.size();
    for (int i=0; i<length; i++) {
        if ((int) input[i] - 48 == 6 || (int) input[i] - 48 == 9) {
            num[6]++;
        }
        else num [(int) input[i] - 48]++;
    }
    for (int i=0; i<9; i++) {
        if (i == 6) {
            temp = ceil(num[i]/2);
            if (count<temp) {
                count = temp;
            }
        }

        else if (count < num[i]) {
            count = num[i];
        }
    }
    cout << count << "\n";
    return 0;
}