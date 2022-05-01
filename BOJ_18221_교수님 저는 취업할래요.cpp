#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector <vector <int>> vvi;

int main()
{
    int n, start_x, start_y, end_x, end_y;
    int pro_x, pro_y, stu_x, stu_y, count = 0;
    double dis;
    vvi table;
    bool flag = false;

    cin >> n;
    table.assign (n, vector<int>(n));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> table[i][j];
            if (table[i][j] == 5) {
                pro_x = i; pro_y = j;
            }
            if (table[i][j] == 2) {
                stu_x = i; stu_y = j;
            }
        }
    }

    dis = (double) sqrt ( pow(pro_x - stu_x, 2) + pow(pro_y - stu_y, 2) );

    if (dis < 5) {
        cout << "0" << "\n";
    }

    else {
        if (pro_x < stu_x) {
        start_x = pro_x;
        end_x = stu_x;
        }
        else {
            start_x = stu_x;
            end_x = pro_x;
        }

        if (pro_y < stu_y) {
            start_y = pro_y;
            end_y = stu_y;
        }
        else {
            start_y = stu_y;
            end_y = pro_y;
        }

        for (int i=start_x; i<=end_x; i++) {
            for (int j=start_y; j<=end_y; j++) {
                if (table[i][j] == 1) count++;
            }
        }

        if (count <3) {
            cout << "0" <<"\n";
        }
        else {
            cout << "1" << "\n";
        }
    }

    

    return 0;
}