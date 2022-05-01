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

    int t, n, input_temp;
    char input;
    long long int max=0, temp;
    vector <int> num;

    cin>>t;
    while(t--){
        cin >> n;
        max=0;
        for (int i=0; i<n; i++){
            cin >> input;
            input_temp = (int)input - 48;
            cout<<input_temp<<"\n";
            if (input == '\n') break;
            num.emplace_back(input_temp);
        }
        
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                temp += gcd(num[i], num[j]);
                if (max<temp) max=temp;
            }
        }
        num.clear();
        cout<<max<<"\n";
    }
    return 0;
}