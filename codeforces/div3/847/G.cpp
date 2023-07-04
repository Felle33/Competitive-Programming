#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

bool dfs(vector<vector<int>>& adj, int vertex, vector<bool>& visited, vector<bool>& tokens, vector<bool>& bonuses){
    if(visited[vertex]) return false;
    visited[vertex] = true;

    if(tokens[vertex]) return true;
    bool isPossible = false;
    if(bonuses[vertex]){
        for(int near : adj[vertex]){
            isPossible |= dfs(adj, near, visited, tokens, bonuses);
            if(isPossible) break;
        }
    }

    return isPossible;
}

void solve(){
    int n, e, t, b;
    cin >> n >> e >> t >> b;

    vector<vector<int>> adj(n);
    vector<bool> bonuses(n);
    vector<bool> tokens(n);
    vector<bool> visited(n);

    for(int i = 0; i < b; i++){
        int b1;
        cin >> b1;
        b1--;
        bonuses[b1] = true;
    }

    for(int i = 0; i < t; i++){
        int t1;
        cin >> t1;
        t1--;
        tokens[t1] = true;
    }

    for(int i = 0; i < e; i++){
        int n1, n2;
        cin >> n1 >> n2;
        n1--, n2--;
        adj[n1].emplace_back(n2);
        adj[n2].emplace_back(n1);
    }

    visited[0] = true;
    bool isPossible = false;

    if(tokens[0]){
        isPossible = true;
    }
    else{
        for(int near : adj[0]){
            isPossible |= dfs(adj, near, visited, tokens, bonuses);

            if(isPossible) break;
        }
    }

    cout << (isPossible ? "YES" : "NO") << endl;
    
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}