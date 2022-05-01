#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector <vector<int>> vvi;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { 1, -1, 0, 0 };

int bfs(int x_input, int y_input, vvi maze, int height, int width) {
    queue <pair<int, int>> q;
    vvi check(height, vector<int>(width));
    int temp, nx, ny, x_temp, y_temp;

    q.push({ x_input, y_input });
    check[x_input][y_input] = 1;

    while (!q.empty()) {
        x_temp = q.front().first; y_temp = q.front().second;
        q.pop();

        if (x_temp == height - 1 && y_temp == width - 1) {
            return check[x_temp][y_temp];
        }

        for (int i = 0; i < 4; i++) {
            nx = x_temp + dx[i]; ny = y_temp + dy[i];
            if (nx >= 0 && nx < height && ny >= 0 && ny < width) {
                if (!check[nx][ny] && maze[nx][ny]) {
                    check[nx][ny] = check[x_temp][y_temp] + 1; 
                    q.push({ nx, ny });
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int height, width, count;
    string temp;
    vvi maze;

    cin >> height >> width;
    maze.assign(height, vector<int>(width));

    for (int i = 0; i < height; i++) { //출력 ok
        cin >> temp;
        for (int j = 0; j < width; j++) {
            maze[i][j] = (int)temp[j] - 48;
        }
    }

    //(1,1)에서 출발 -> 0 0먼저 집어넣기
    count = bfs(0, 0, maze, height, width);
    cout << count << "\n";
    return 0;
}