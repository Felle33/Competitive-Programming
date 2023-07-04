#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>
#include <stack>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<int>> graph_trasposed;

void dfs(int node, vector<bool>& visited, vector<vector<int>>& g){
    visited[node] = true;

    for(int e : g[node]){
        if(!visited[e]){
            dfs(e, visited, g);
        }
    }
}

void solve(){
    cin >> n >> m;
    graph.resize(n);
    graph_trasposed.resize(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph_trasposed[b].push_back(a);
    }

    vector<bool> visited(n);
    dfs(0, visited, graph);

    for(int i = 1; i < n; i++){
        if(!visited[i]){
            cout << "NO" << '\n';
            cout << 1 << " " << i + 1 << '\n';
            return;
        }
    }

    fill(all(visited), false);
    dfs(0, visited, graph_trasposed);

    for(int i = 1; i < n; i++){
        if(!visited[i]){
            cout << "NO" << '\n';
            cout << i + 1 << " " << 1 << '\n';
            return;
        }
    }

    cout << "YES";

}

int main(){
    /* freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout); */
    solve();
} 