#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef queue <pair<int,int>> qpi;

int bfs (int n, int k)
{
    int s_locate, sec, ans;
    int nx1, nx2, nx3;
    qpi table;
    bool check[200004] = {false, };

    table.push({ n, 0 }); // table{현재 위치, 그 위치까지 오는데 걸린 시간}
    check [n] = true;

    while (!table.empty()) {
        s_locate = table.front().first; sec = table.front().second;
        table.pop();

        nx1 = s_locate - 1;
        nx2 = s_locate + 1;
        nx3 = s_locate * 2;

        if (s_locate == k) {
            ans = sec;
            break;
        }

        if (nx1 >= 0 && nx1 < 100001 && !check[nx1]) {
            table.push({ nx1, sec + 1 });
            check[nx1] = true;
        }
    
        if (nx2 >= 0 && nx2 < 100001 && !check[nx2]) {
            table.push({ nx2, sec + 1 });
            check[nx2] = true;
        }

        if (nx3 >= 0 && nx3 < 100001 && !check[nx3]) {
            table.push({ nx3, sec + 1 });
            check[nx3] = true;
        }
    }
    return ans;
}

int main()
{
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k, ans;
    cin >> n >> k;
    
    ans = bfs(n, k);
    cout << ans << "\n";
    return 0;
}