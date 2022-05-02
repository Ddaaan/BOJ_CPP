#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int temp;
    if (a<b) {
        temp = a;
        a = b;
        b = temp;
    }
    while (b!=0) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int lcm(int x, int y)
{
    return (x*y) / gcd(x, y);
}

int main() 
{
    int n, temp, num;
    cin >> n;
    cin >> num;
    for (int i=0; i<n-1; i++) {
        cin >> temp;
        num = gcd(num, temp);
    }
    for (int i=1; i<=num; i++) {
        if (num % i == 0) cout << i <<"\n";
    }
    return 0;
}