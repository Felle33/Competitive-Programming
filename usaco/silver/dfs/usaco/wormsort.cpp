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
vector<vector<pair<int, int>>> graph;
int nodesReached;

void dfs(int node, vector<bool>& visited, int minWeight){
    visited[node] = true;

    for(int i = 0; i < (int) graph[node].size(); i++){
        if(!visited[graph[node][i].first] && graph[node][i].second >= minWeight){
            nodesReached++;
            dfs(graph[node][i].first, visited, minWeight);
        }
    }
}

void solve(){
    cin >> n >> m;

    graph.resize(n);
    vector<int> perm(n);
    vector<bool> nodesSorted(n);

    int lastNotSorted;
    for(int i = 0; i < n; i++){
        cin >> perm[i];
        if(perm[i] == i + 1){
            nodesSorted[i] = true;
        }
        else{
            lastNotSorted = i;
        }
    }

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    
    bool sorted = true;
    for(int i = 0; i < n; i++){
        if(perm[i] != i + 1) sorted = false;
    }

    if(sorted){
        cout << -1;
        return;
    }

    int l = 1, r = 1e9 + 1;
    vector<bool> visited(n);
    while(l + 1 < r){
        int mid = l + (r - l) / 2;
        nodesReached =  1;
        fill(all(visited), false);
        dfs(lastNotSorted, visited, mid);

        for(int i = 0; i < n; i++){
            if(nodesSorted[i] && !visited[i]){
                nodesReached++;
            }
        }

        if(nodesReached == n){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    cout << l;
}

int main(){
    freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
    solve();
} 