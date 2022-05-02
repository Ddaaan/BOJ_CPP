#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    int temp;
    if (x<y) {
        temp = x;
        x = y;
        y = temp;
    }
    while (y!=0) {
        temp = x;
        x = y;
        y = temp % y;
    }
    return x;
}

int main() 
{
    int n, m, gcd_n;
    char temp;
    cin >> n >> temp >> m;
    
    gcd_n = gcd(n, m);
    cout << n/gcd_n << ":" << m/gcd_n << "\n";
    return 0;
}