#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int first_x, first_y, second_x, second_y, last_x, last_y;
    double a, b, c;
    double angle_a, angle_b, angle_c, max_angle = 0;
    bool flag = false;

    cin >> first_x >> first_y;
    cin >> second_x >> second_y;
    cin >> last_x >> last_y;

    a = sqrt(pow(first_x - second_x, 2) + pow(first_y - second_y, 2));
    b = sqrt(pow(second_x - last_x, 2) + pow(second_y - last_y, 2));
    c = sqrt(pow(last_x - first_x, 2) + pow(last_y - first_y, 2));

    angle_a = (double) (pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c);
    if (max_angle < angle_a) max_angle = angle_a;
    angle_b = (double) (pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c);
    if (max_angle < angle_b) max_angle = angle_b;
    angle_c = (double) (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);
    if (max_angle < angle_c) max_angle = angle_c;

    cout << "a : " << a << " b : " << b << " c : " << c << "\n";
    cout << "a.a : " << angle_a << " a.b : " << angle_b << " a.c : " << angle_c << "\n";
    cout << max_angle << "\n";

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

    if (!flag) {
        if (a==b && b==c && c==a) {
            cout << "JungTriangle" << "\n";
        }

        else if (a!=b && b!=c && c!=a) {
            if (max_angle > 0) {
                cout << "DunkakTriangle" << "\n";
            }
            else if (max_angle == 0) {
                cout << "JikkakTriangle" << "\n";
            }
            else cout << "YeahkakTriangle" << "\n";
        }

        else {
            if (max_angle > 0) {
                cout << "Dunkak2Triangle" << "\n";
            }
            else if (max_angle == 0) {
                cout << "Jikkak2Triangle" << "\n";
            }
            else cout << "Yeahkak2Triangle" << "\n";
        }
    }    
    
    //cos 90 = 0

    return 0;

}