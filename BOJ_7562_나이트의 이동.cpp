#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

const int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
const int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };

void move(int start_x, int start_y, int target_x, int target_y, int length, vvi& chess, vvb& check) {
    int temp_x, temp_y, x, y;
    queue <pair<int, int>> q;
    q.push({ start_x, start_y });
    check[start_x][start_y] = true;

    while (!q.empty())
    {
        x = q.front().first; y = q.front().second;
        q.pop();

        if (x == target_x && y == target_y) {
            cout << chess[x][y] << "\n";
            return;
        }
        for (int i = 0; i < 8; i++) {
            temp_x = x + dx[i]; temp_y = y + dy[i];
            if (temp_x >= 0 && temp_x < length && temp_y >= 0 && temp_y < length) {
                if (!check[temp_x][temp_y]) {
                    chess[temp_x][temp_y] = chess[x][y] + 1;
                    check[temp_x][temp_y] = true;
                    q.push({ temp_x, temp_y });
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, length, start_x, start_y, target_x, target_y;
    vvi chess;
    vvb check;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> length;
        chess.assign(length, vector<int>(length, 0));
        check.assign(length, vector<bool>(length, false));

        cin >> start_x >> start_y;
        cin >> target_x >> target_y;

        move(start_x, start_y, target_x, target_y, length, chess, check);
        chess.clear();
        check.clear();
    }
    return 0;
}