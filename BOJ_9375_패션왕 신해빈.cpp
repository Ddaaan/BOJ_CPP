#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map <string, int> m;
    int t, n, ans=1;
    string name, kind;

    cin>>t;
    while(t--) {
        ans = 1;
        cin>>n;
        while(n--) {
            cin >> name >> kind;
            
            if (m.find(kind) == m.end()) {
                m [kind] = 1;
            }
            else m [kind]++;
        }

        for (auto temp : m){
            ans *= (temp.second + 1);
        }
        cout << ans - 1 << "\n";
        m.erase (m.begin(), m.end());
    }
    return 0;
}