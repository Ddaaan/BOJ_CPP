#include <iostream>

using namespace std;

int fibonacci(int n, int &count_0, int &count_1) {
    if (n == 0) {
        count_0++;
        return 0;
    } else if (n == 1) {
        count_1++;
        return 1;
    } else {
        return fibonacci(n-1, count_0, count_1) + fibonacci(n-2, count_0, count_1);
    }
}

int main(){
    int t, num, count_0=0, count_1=0;
    for (int i=0; i<t; i++){
        count_0=0; count_1=0;
        cin>>num;
        fibonacci(num, count_0, count_1);
        cout<<count_0<<' '<<count_1;
    }
    return 0;
}