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
#define pii pair<int,int>

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const int INF = 1e9;

vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n, m;
vector<vector<int>> graph;

void bfs(int start, vector<int>& distance_from_start){
    vector<bool> visited(n);
    queue<int> q;

    q.push(start);
    visited[start] = true;
    distance_from_start[start] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int adj : graph[u]){
            if(!visited[adj]){
                q.push(adj);
                distance_from_start[adj] = distance_from_start[u] + 1;
                visited[adj] = true;
            }
        }
    }
}

void solve(){
    ll b, e, p;
    cin >> b >> e >> p >> n >> m;
    graph.resize(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> distance_from_1(n);
    vector<int> distance_from_2(n);
    vector<int> distance_from_n(n);

    bfs(0, distance_from_1);
    bfs(1, distance_from_2);
    bfs(n - 1, distance_from_n);

    ll ans = distance_from_1[n - 1] * b + distance_from_2[n - 1] * e;

    for(int i = 0; i < n; i++) {
        ans = min(ans, distance_from_1[i] * b + distance_from_2[i] * e
        + distance_from_n[i] * p);
    }
    
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("piggyback.in", "r", stdin);
	freopen("piggyback.out", "w", stdout);

    solve();
}