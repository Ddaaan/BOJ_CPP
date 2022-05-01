#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> vvi;
typedef queue<pair<int,int>> qp;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

int bfs(vvi tomato, vvi &check, int height, int width, qp &red) {
    int max=0, count_func=0;
    int nx, ny, start_x, start_y;

    for (int i=0; i<height; i++) { //check배열에 0이 있으면 이미 익어있는 것
        for (int j=0; j<width; j++) {
            if (check[i][j] == 0) count_func++; //count_func => 처음부터 익어있던 토마토의 수
        }
    }

    if (count_func == (height * width)) return 0; //만약 입력받은 전체 개수 - 원래 없던 칸 = 처음부터 익어있던 토마토의 수 이면 0 return

    while(!red.empty()) {
        start_x = red.front().first; start_y = red.front().second;
        red.pop();
        for (int i=0; i<4; i++) {
            nx = start_x + dx[i]; ny = start_y + dy[i];
            if (nx >= 0 && nx < height && ny >= 0 && ny < width) {
                if (check[nx][ny] == -1 && tomato[nx][ny] == 0) {
                    check[nx][ny] = check[start_x][start_y] + 1;
                    if (max < check[nx][ny]) max = check[nx][ny];
                    red.push({nx, ny});
                }
            }
        }
    }
    return max;
}

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int width, height, ans, count=0, result_count=0;
    vvi tomato;
    vvi check;
    qp red;
    cin>>width>>height;
    
    tomato.assign(height, vector<int>(width));
    check.assign(height, vector<int>(width, -1)); //초기값 -1로 설정 (처음부터 익어있는거 0일차로 설정하기 위하여)

    for (int i=0; i<height; i++){ //input -> done
        for (int j=0; j<width; j++){
            cin>>tomato[i][j];
            if (tomato[i][j] == -1) count++; //처음부터 없었던 칸수 세어주기
            if (tomato[i][j] == 1) {
                red.push({i, j}); //익은 토마토가 있는 좌표 queue에 저장하기
                check[i][j] = 0; //원래 익어있는건 0일차 때 익었다고 가정
            }
        }
    }

    ans = bfs(tomato, check, height, width, red);

    for (int i=0; i<height; i++) { //bfs통과 후에도 check배열에 -1로 남아있으면 익지 못한 토마토임
        for (int j=0; j<width; j++) {
            if (check[i][j] == -1) result_count++; //-1이면 result_count개수를 올려줌
        }
    }
    if (count < result_count) ans = -1;

    cout << ans << "\n";
    return 0;
}