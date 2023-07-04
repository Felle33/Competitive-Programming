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

void dfs(int node, vector<bool>& visited){
    visited[node] = true;

    for(int e : graph[node]){
        if(!visited[e]){
            dfs(e, visited);
        }
    }
}

void solve(){
    cin >> n >> m;

    graph.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n);
    vector<int> capitals;
    int ans = 0;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            capitals.push_back(i);
            dfs(i, visited);

            if(i != 0){
                ans++;
            } 
        }
    }

    cout << ans << '\n';
    for(int i = 0; i < ans; i++){
        cout << capitals[i] + 1 << " " << capitals[i + 1] + 1 << " ";
    }
}

int main(){
    /* freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout); */
    solve();
} 