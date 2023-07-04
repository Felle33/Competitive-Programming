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

vector<vector<int>> graph;

void initialize(){
    for(int i = 0; i < (int)graph.size(); i++) graph[i].clear();
}

void dfs(int node, vector<bool>& visited){
    visited[node] = true;

    for(int e : graph[node]){
        visited[e] = true;
    }
}

void solve(){
    int n, m;
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
    vector<int> parity[2];
    visited[0] = true;
    queue<int> q;
    q.push(0);
    int dist = 1;
    parity[0].push_back(0);

    while(!q.empty()){
        int cycles = q.size();
        while(cycles--){
            int node = q.front();
            q.pop();

            for(int e : graph[node]){
                if(!visited[e]){
                    q.push(e);
                    visited[e] = true;
                    parity[dist % 2].push_back(e);
                }
            }
        }
        dist++;
    }

    if(parity[0].size() < parity[1].size()){
        cout << parity[0].size() << '\n';

        for(int x : parity[0]){
            cout << x + 1 << " ";
        }
    }
    else{
        cout << parity[1].size() << '\n';

        for(int x : parity[1]){
            cout << x + 1 << " ";
        }
    }

    cout << "\n";
}

int main(){
    /* freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout); */
    int t;
    cin >> t;
    while(t--){
        initialize();
        solve();
    }
} 