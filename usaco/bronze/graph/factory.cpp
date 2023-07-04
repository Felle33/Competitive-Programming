#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

typedef long long ll;
using namespace std;

int dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
    visited[node] = true;
    int res = 0;

    for(int a : adj[node]){
        if(!visited[a]){
            res += dfs(a, adj, visited);
        }
    }

    return res + 1;
}

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;

        a--, b--;
        adj[b].push_back(a);
    }

    vector<bool> visited(n);
    bool found = false;
    for(int i = 0; i < n; i++){
        fill(visited.begin(), visited.end(), 0);
        if(dfs(i, adj, visited) == n){
            cout << i + 1 << '\n';
            found = true;
            break;
        }
    }

    if(!found){
        cout << -1 << '\n';
    }
}

int main(){
    freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);
    solve();
} 