#include <iostream>
#include <cmath>

using namespace std;

void swap(double &a, double &b, double &c)
{
    double temp;
    if (a>b) {
        temp = a;
        a = b;
        b = temp;
    }

    if (b>c) {
        temp = b;
        b = c;
        c = temp;
    }

    if (a>c) {
        temp = a;
        a = c;
        c = temp;
    }
}

int main() 
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int first_x, first_y, second_x, second_y, last_x, last_y;
    double a, b, c;
    bool flag = false;

    cin >> first_x >> first_y;
    cin >> second_x >> second_y;
    cin >> last_x >> last_y;

    a = sqrt(pow(first_x - second_x, 2) + pow(first_y - second_y, 2));
    b = sqrt(pow(second_x - last_x, 2) + pow(second_y - last_y, 2));
    c = sqrt(pow(last_x - first_x, 2) + pow(last_y - first_y, 2));

    //a<b<c
    cout << a <<' ' << b << ' '<< c << "\n";

    if ((first_x == second_x && second_x == last_x) || (first_y == second_y && second_y == last_y)) {
        cout << "X" << "\n";
        flag = true;
    }

    else if (first_x - second_x != 0 && second_x - last_x != 0){
        if ((double)((first_y - second_y)/(first_x - second_x)) == (double)((second_y - last_y)/(second_x - last_x))) {
            cout << "X" << "\n";
            flag = true;
        }
    }
}