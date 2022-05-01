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
	while (y != 0){
		temp = x;
		x = y;
		y = temp % y;
	}
	return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, input;
    long long int sum=0;
    vector <int> num;

    cin>>t;
    while(t--){
        cin >> n;
        sum=0;
        for (int i=0; i<n; i++){
            cin >> input;
            num.emplace_back(input);
        }
        
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                sum += gcd(num[i], num[j]);
            }
        }
        num.clear();
        cout<<sum<<"\n";
    }
    return 0;
}