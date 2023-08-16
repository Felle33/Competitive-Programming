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

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

struct edge {
    int a, b;
};


void dfs(int node, vector<vector<bool>>& graph, vector<bool>& visited) {
    visited[node] = true;

    int p = graph.size();
    for(int i = 0; i < p; i++) {
        if(graph[node][i] && !visited[i]) {
            dfs(i, graph, visited);
        }
    }
}

bool solve(){
    int p, c;
    cin >> p >> c;

    if(p == 0 && c == 0) return false;
    vector<vector<bool>> graph(p, vector<bool>(p));
    vector<bool> visited(p);
    vector<edge> edges;

    for(int i = 0; i < c; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
        edges.push_back({a, b});
    }

    for(edge e : edges) {
        graph[e.a][e.b] = false;
        graph[e.b][e.a] = false;
        dfs(0, graph, visited);
        for(int k = 0; k < p; k++) {
            if(!visited[k]) {
                cout << "Yes\n";
                return true;
            }
        }
        graph[e.a][e.b] = true;
        graph[e.b][e.a] = true;
        fill(all(visited), false);
    }

    cout << "No\n";
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout); */
    while(solve());
    
} 