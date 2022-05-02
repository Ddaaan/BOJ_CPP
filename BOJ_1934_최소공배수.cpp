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

int lcm(int x, int y)
{
    return (x*y) / gcd(x, y);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    
    int t, num_a, num_b;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> num_a >> num_b;
        cout << lcm (num_a, num_b) << "\n";
    }
    return 0;
}