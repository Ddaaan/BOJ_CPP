#include <iostream>

using namespace std;

int main() 
{
    int temp, l, p, people;
    cin >> l >> p;
    temp = l*p;
    for (int i=0; i<5; i++) {
        cin >> people;
        cout << people-temp << ' ';
    }
    return 0;
}