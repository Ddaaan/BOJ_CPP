#include <iostream>
#include <set>

using namespace std;

int main(){
    string name, work;
    set <string, greater<>> s;
    int n, length;

    cin>>n;
    while(n--){
        cin>>name>>work;
        if (work == "enter"){
            s.insert(name);
        }
        else s.erase(name);
    }
    length = s.size();
    for (set<string>::iterator iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << "\n";
	}
    return 0;
}