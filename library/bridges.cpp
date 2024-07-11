#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

vector<vector<int>> adj, ans;
vector<int> tin, low;
vector<bool> visited;
int times = 0;

void dfs(int u, int p) {
    visited[u] = 1;
    tin[u] = times++;
    low[u] = tin[u];

    for(int to : adj[u]) {
        if(to != p) {
            if(!visited[to]) {
                dfs(to, u);

                // BRIDGE!
                if(tin[u] < low[to]) {
                    ans.push_back({u, to});
                }
            }
            
            low[u] = min(low[u], low[to]);
        }
    }
}

// Leetcode: 1192
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    adj = vector<vector<int>>(n);
    tin = vector<int>(n);
    low = vector<int>(n);
    visited = vector<bool>(n);

    for(vector<int>& con : connections) {
        adj[con[0]].push_back(con[1]);
        adj[con[1]].push_back(con[0]);
    }

    dfs(0, 0);

    return ans;
}