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
vector<bool> visited;
vector<int> ans;

bool dfs(int maxStreet, int edges, int node, bool store){
    if(edges == 0 && node != n - 1) return false;
    if(node == n - 1){
        if(store) ans.push_back(node);
        return true;
    }

    visited[node] = true;
    for(const pair<int, int>& p : graph[node]){
        if(!visited[p.first] && p.second <= maxStreet){
            if(store){
                ans.push_back(node);
                if(dfs(maxStreet, edges - 1, p.first, store)){
                    return true;
                }
                ans.pop_back();
            }
            else{
                if(dfs(maxStreet, edges - 1, p.first, store)){
                    return true;
                }
            }
            
        }
    }

    return false;
}

void solve(){
    cin >> n >> m >> d;

    graph.resize(n);
    visited.resize(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        graph[a].push_back({b, c});
    }
    
    bool found = dfs(1e9 + 1, d, 0, false);

    if(!found){
        cout << -1 << '\n';
        return;
    }

    int l = -1, r = 1e9 + 1;
    while(l + 1 < r){
        int mid = l + (r - l) / 2;
        fill(all(visited), false);
        if(dfs(mid, d, 0, false)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    
    fill(all(visited), false);
    dfs(r, d, 0, true);

    cout << (int)ans.size() - 1 << '\n';
    for(int i = 0; i < (int) ans.size(); i++){
        cout << ans[i] + 1 << " ";
    }
    cout << '\n';
}

int main(){
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 