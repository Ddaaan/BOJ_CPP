#include <iostream>
#include <vector>

using namespace std;

void eratos(int n, int k) 
{
    int count=0;
    vector<bool>arr (n+1, false);

    for (int i=2; i<=n; i++) {
        for (int j=i; j<=n; j+=i) {
            if (arr[j] == false) {
                arr[j] = true;
                count++;
                if (count == k) {
                    cout << j << "\n";
                }
            }
        }
        if (count == k) break;
    }
}

int main() 
{
    int n, k;
    cin >> n >> k;
    eratos(n, k);
    return 0;
}