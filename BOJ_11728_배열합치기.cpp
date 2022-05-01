#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n, m, temp;
    vector <int> arr;
    cin >> n >> m;

    for (int i=0; i<n; i++){
        cin >> temp;
        arr.emplace_back(temp);
    }

    for (int i=0; i<m; i++){
        cin >> temp;
        arr.emplace_back(temp);
    }

    sort(arr.begin(), arr.end());

    cout << arr[0] << ' ';
    for (int i=1; i<n+m; i++) {
        if (arr[i]!=arr[i-1]) {
            cout << arr[i] << ' ';
        }
    }

    return 0;

}