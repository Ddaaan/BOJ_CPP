#include <iostream>

using namespace std;

typedef long long int ll;

ll gcd(ll x, ll y) {
	int temp;
	if (x < y) {
		temp = x;
		x = y;
		y = temp;
	}
	while (y != 0)
	{
		temp = x;
		x = y;
		y = temp % y;
	}
	return x;
}

ll lcm(ll x, ll y) {
	return (x * y) / gcd(x, y);	
}

int main() 
{
    ll a, b;
    cin >> a >> b;
    cout << lcm (a, b) << "\n";
    return 0;
}