#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

void dfs(int x, int y, vvi table, vvb &check, int height, int width){
    int nx, ny;

    for (int i=0; i<4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < height && ny < width){
            if (table[nx][ny] && !check[nx][ny]){
                check[nx][ny] = true;
                dfs(nx, ny, table, check, height, width);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int height, width, n, x, y, t, count=0; //height = 세로, width = 가로
    vvi table;
    vvb check;
    cin >> t;

    for (int i=0; i<t; i++){
        count=0;
        cin >> width >> height >> n;
        table.assign(height,vector<int>(width));
        check.assign(height,vector<bool>(width, false));

        for (int i=0; i<n; i++){
            cin >> x >> y;
            table[y][x] = 1;
        }

        for (int i=0; i<height; i++){
            for (int j=0; j<width; j++){
                if (!check[i][j] && table[i][j]){
                    check[i][j]=true;
                    count++;
                    dfs(i, j, table, check, height, width);
                }
            }
        }
        cout<<count<<"\n";
    }

    return 0;
}