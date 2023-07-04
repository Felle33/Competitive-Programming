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

int n, m;
vector<vector<int>> graph;
vector<pair<ll, ll>> cows;

ll xMin = 1e9, xMax = 0, yMin = 1e9, yMax = 0;

void dfs(int node, vector<bool>& visited){
    visited[node] = true;
    xMin = min(xMin, cows[node].first);
    xMax = max(xMax, cows[node].first);
    yMin = min(yMin, cows[node].second);
    yMax = max(yMax, cows[node].second);

    for(int e : graph[node]){
        if(!visited[e]){
            dfs(e, visited);
        }
    }
}

void solve(){
    cin >> n >> m;
    cows.resize(n);
    graph.resize(n);

    for(int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n);
    ll ans = 1e10;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            xMin = 1e9, xMax = 0, yMin = 1e9, yMax = 0;
            dfs(i, visited);
            ans = min(ans, (xMax - xMin) * 2 + (yMax - yMin) * 2);
        }
    }

    cout << ans;
}

int main(){
    freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
    solve();
} 