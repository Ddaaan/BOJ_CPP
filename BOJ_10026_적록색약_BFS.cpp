#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<string>> vvs;
typedef vector<vector<bool>> vvb;

const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

int normal(vvs table, vvb check, int x, int y, int n){
    int func_x, func_y;
    int next_x, next_y;
    int count=0;

    queue<pair<int, int>> q;
    q.push({x,y});
    check[x][y]=true;

    while(!q.empty()){
        func_x=q.front().first; func_y=q.front().second;
        q.pop();
        for (int i=0; i<4; i++){
            next_x=func_x+dx[i]; next_y=func_y+dy[i];
            if (next_x>=0 && next_x < n && next_y>=0 && next_y < n){
                if (!check[next_x][next_y] && table[next_x][next_y] == table[x][y]){
                    check[next_x][next_y] = true;
                    q.push({next_x, next_y});
                    count++;
                }
            }
        }
    }
    return count;
}

int non_normal(vvs table, vvb check, int x, int y, int n){

    int func_x, func_y;
    int next_x, next_y;
    int count=0;

    queue<pair<int, int>> q;
    q.push({x,y});
    check[x][y]=true;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (table[i][j] =="R") table[i][j]="G";
        }
    }

    while(!q.empty()){
        func_x=q.front().first; func_y=q.front().second;
        q.pop();
        for (int i=0; i<4; i++){
            next_x=func_x+dx[i]; next_y=func_y+dy[i];
            if (next_x>=0 && next_x < n && next_y>=0 && next_y < n){
                if (!check[next_x][next_y] && table[next_x][next_y] == table[x][y]){
                    check[next_x][next_y] = true;
                    q.push({next_x, next_y});
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, ans1, ans2;
    string str;
    vvs table;
    vvb check;

    cin >> n;

    table.assign(n, vector<string>(n));
    check.assign(n,vector<bool>(n,false));

    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            table[i][j] = str[j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
        ans1=normal(table, check, i, j, n);
        ans2=non_normal(table, check, i, j, n);
        }
    }
    cout<<ans1<<' '<<ans2<<"\n";
    return 0;   
}