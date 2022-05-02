#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void eratos(int n, vector<bool> &check)
{
    check[0] = true;
    check[1] = true;
    for (int i=2; i<=sqrt(n); i++) {
        if (check[i] == false) {
            for (int j = i+i; j<=n; j+=i) {
                check[j] = true;
            }
        }
    }
}

int main() 
{
    int m, n;
    cin >> m >> n;
    vector<bool> check(n+1, false);
    eratos(n, check);
    for (int i=m; i<=n; i++) {
        if (!check[i]) {
            cout << i << "\n";
        }
    }
    return 0;
}