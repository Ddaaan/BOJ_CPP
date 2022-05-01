#include <iostream> 

using namespace std;

int main() {
    ios::sync_with_stdio (false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num1;
    string num2;
    int a,b,c, num;

    cin >> num1 >> num2;
    a = (int) num2[2] - 48;
    b = (int) num2[1] - 48;
    c = (int) num2[0] - 48;
    num = stoi(num2);

    cout << num1 * a <<"\n";
    cout << num1 * b << "\n";
    cout << num1 * c << "\n";
    cout << num1 * num << "\n";

    return 0;
}