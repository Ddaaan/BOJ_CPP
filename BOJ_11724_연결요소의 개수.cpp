#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;

void dfs(vvi &graph, vector<bool> &check, int now){
    int temp;
    check[now]=true;

    for (int i=0; i<graph[now].size(); i++){
        temp=graph[now][i];
        if (!check[temp]){
            dfs(graph, check, temp);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int node, line, start, end, count=0;
    vvi graph;
    vector <bool> check;
    cin >> node >> line;

    graph.assign(node,vector<int>());
    check.assign(node,false);

    for (int i=0; i<line; i++){
        cin >> start >> end;
        start--; end--;
        graph[start].emplace_back(end);
        graph[end].emplace_back(start);
    }

    for (int i=0; i<node; i++){
        if (!check[i]){
            count++;
            dfs(graph, check, i);
        }
    }
    cout<<count<<"\n";
    return 0;
}