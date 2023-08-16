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
#define f first
#define s second
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n, m;
vector<vector<int>> adj;
vector<int> shortest_distance;
vector<int> cnt;

void bfs() {
    queue<int> q;
    vector<bool> visited(n);
    q.push(0);
    visited[0] = true;
    cnt[0] = 1;
    int dis = 0;

    while(!q.empty()) {
        int cycles = q.size();
        while(cycles--) {
            int node = q.front();
            q.pop();

            for(int a : adj[node]) {
                if(!visited[a]) {
                    shortest_distance[a] = shortest_distance[node] + 1;
                    cnt[a] = cnt[node];
                    q.push(a);
                    visited[a] = true;
                } else if(shortest_distance[a] == shortest_distance[node] + 1) {
                    cnt[a] = (cnt[a] + cnt[node]) % MOD;
                }
            }
        }
        dis++;
    }
}

void solve(){
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    shortest_distance = vector<int>(n);
    cnt = vector<int>(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs();

    cout << cnt[n - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}