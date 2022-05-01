#include <iostream>

using namespace std;

int main() 
{
    int n, count = 0, lenght, dis;
    int one, ten, hun;
    bool flag = true;

    cin >> n;
    for (int i=1; i<=n; i++) {
        if (i < 100) count++;
        else {
            one = i % 10;
            ten = i % 100 / 10;
            hun = i / 100;
            if (one - ten == ten - hun) count++;
        }
    }
    cout << count << "\n";
    return 0;
}