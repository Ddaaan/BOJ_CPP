#include <iostream>

using namespace std;

int main () 
{
    bool num[10001] = {false, };
    int n, result;
    for (int i=1; i<=10000; i++) {
        n = i; result = i;
        while (n > 0){
            result += (n % 10);
            n /= 10;            
        }
        if (result < 10001) num[result] = true;
    }

    for (int i=1; i<10001; i++) {
        if (!num[i]) cout << i << "\n";
    }
    return 0;
}