#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y) {
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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cir, temp, gcd_n;
    vector<int> ring;
    cin >> n;
    
    for (int i=0; i<n; i++) {
        cin >> temp;
        ring.emplace_back(temp);
    }
    cir = ring[0];
    for (int i=1; i<n; i++) {
        gcd_n = gcd(cir, ring[i]);
        cout << cir/gcd_n << "/" << ring[i]/gcd_n << "\n";
    }
    return 0;
}