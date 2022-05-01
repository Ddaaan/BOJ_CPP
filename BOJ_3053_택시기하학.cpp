#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(6);

    int r;
    double u, t, pi = 3.1415926535897932;
    cin >> r;

    u = pow(r, 2) * pi;
    t = pow(r, 2) * 2;
    cout << u << "\n" << t << "\n";
    return 0;
}