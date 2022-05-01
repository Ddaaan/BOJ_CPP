#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;

const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

void normal(vvc &table, vvb &check, int x, int y, int n){
    int nx, ny;
    check[x][y]=true;

    for (int i=0; i<4; i++){
        nx = x + dx[i];
		ny = y + dy[i];

    	if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (table[nx][ny] == table[x][y] && !check[nx][ny]){
                normal(table, check, nx, ny, n);
            }
        }
    }
}

void change_color(vvc &table, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (table[i][j] =='G') table[i][j]='R';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, ans1, ans2;
    string str;
    vvc table;
    vvb check;
    int count=0;

    cin >> n;

    table.assign(n, vector<char>(n));
    check.assign(n,vector<bool>(n,false));

    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            table[i][j] = str[j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (!check[i][j]){
                count++;
                normal(table, check, i, j, n);
            }
        }
    }
    ans1=count;
    change_color(table, n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            check[i][j]=false;
        }
    }

    count=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (!check[i][j]){
                count++;
                normal(table, check, i, j, n);
            }
        }
    }
    ans2=count;
    cout<<ans1<<' '<<ans2<<"\n";
    return 0;
}