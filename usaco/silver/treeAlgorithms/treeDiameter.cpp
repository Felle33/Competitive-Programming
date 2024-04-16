#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <iomanip>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

void solve(){
    int n; cin >> n;

    vector<vector<int>> adj(n);
    for(int i; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int mostDistant = -1;
    queue<int> q;
    vector<bool> visited(n);

    q.push(0);
    visited[0] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        mostDistant = node;

        for(int to : adj[node]) {
            if(!visited[to]) {
                visited[to] = 1;
                q.push(to);
            }
        }
    }

    fill(all(visited), 0);
    q.push(mostDistant);
    visited[mostDistant] = 1;
    int distance = 0;

    while(!q.empty()) {
        int cycles = q.size();

        while(cycles--) {
            int node = q.front();
            q.pop();
            mostDistant = node;

            for(int to : adj[node]) {
                if(!visited[to]) {
                    visited[to] = 1;
                    q.push(to);
                }
            }
        }

        distance++;
    }
    distance--;
    cout << distance << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout); */
    solve();
} 