#include <iostream> 
#include <vector>
#include <string>

using namespace std;

const int MAX = 1004000;

void eratos(int n, vector<int>&arr) //소수 구하기 알고리즘
{
    vector<bool> check(MAX+1, false);
    check[0] = true;
    check[1] = true;
    for (int i=2; i*i<=MAX; i++) {
        if (!check[i]) {
            for (int j=i+i; j<=MAX; j+=i) {
                check[j] = true;
            }
        }
    }
    for (int i=n; i<=MAX; i++) {
        if (!check[i]) {
            arr.emplace_back(i);
        }
    }
}

bool reverse(int n)
{
    string num = to_string(n);
    int length = num.size();
    bool flag = true;

    for (int i=0, j=length-1; i<length, j>=0; i++, j--) {
        if (num[i] != num[j]) flag = false;
    }
    return flag;
}

int main() 
{
    int n;
    vector<int> prime;
    cin >> n;

    eratos(n, prime); //n보다 크거나 같은 소수 구하기

    for (int i=0; i<=MAX; i++) {
        if (reverse(prime[i])) {
            cout << prime[i] << "\n";
            break;
        }
    }

    return 0;
}