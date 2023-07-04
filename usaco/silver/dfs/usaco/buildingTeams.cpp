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
vector<int> colors;
bool possible = true;

void dfs(int node, vector<bool>& visited, int color){
    visited[node] = true;
    colors[node] = color;

    for(int e : graph[node]){
        int newColor = color == 1 ? 2 : 1;
        if(!visited[e]){
            dfs(e, visited, newColor);
        }
        else if(colors[e] != newColor){
            possible = false;
        }
    }
}

void solve(){
    cin >> n >> m;

    graph.resize(n);
    colors.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n);

    for(int i = 0; i < n && possible; i++){
        if(!visited[i]){
            dfs(i, visited, 1);
        }
    }
    
    if(possible){
        for(int i = 0; i < n; i++){
            cout << colors[i] << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
}

int main(){
    /* freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout); */
    solve();
} 