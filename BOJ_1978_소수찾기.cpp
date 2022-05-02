#include <iostream>
#include <cmath>

using namespace std;

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num, count=0;
    int flag =false;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> num;
        flag = false;

        if (num==1) continue;
        for (int j=2; j<=sqrt(num); j++) {
            if (num % j == 0) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            count++;
        }       
    }
    cout << count << "\n";
    return 0;
}