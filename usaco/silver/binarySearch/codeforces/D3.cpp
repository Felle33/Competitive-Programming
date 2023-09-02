#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int n, m, d;
vector<vector<pair<int, int>>> graph;
vector<int> parent;

bool bfs(ll maxStreet, bool store){
    queue<int> q;
    q.push(1);
    vector<bool> visited(n + 1);
    if(store) {
        parent = vector<int>(n + 1);
        parent[1] = -1;
    }
    
    visited[1] = 1;
    int distance = 1;

    while(!q.empty() && distance <= d) {
        int cycles = q.size();
        while(cycles--) {
            int node = q.front();
            q.pop();

            for(pair<int, int> p : graph[node]) {
                if(!visited[p.first] && p.second <= maxStreet) {
                    visited[p.first] = 1;
                    q.push(p.first);
                    if(store) parent[p.first] = node;
                    if(p.first == n) return true;
                }
            }
        }
        distance++;
    }

    return false;
}

void solve(){
    cin >> n >> m >> d;

    graph.resize(n + 1);
    int maxStreet = -1;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        maxStreet = max(maxStreet, c);
        graph[a].push_back(make_pair(b, c));
    }
    
    bool found = bfs(maxStreet, 0);

    if(!found){
        cout << -1 << '\n';
        return;
    }

    ll l = -1, r = maxStreet;
    while(l + 1 < r){
        ll mid = l + (r - l) / 2;

        if(bfs(mid, 0)){
            r = mid;
        } else {
            l = mid;
        }
    }
    
    bfs(r, 1);

    vector<int> ans;
    int node = n;
    
    while(node != -1) {
        ans.push_back(node);
        node = parent[node];
    }
    reverse(all(ans));

    int p = ans.size();
    cout << p - 1 << '\n';
    for(int i = 0; i < p; i++){
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
} 