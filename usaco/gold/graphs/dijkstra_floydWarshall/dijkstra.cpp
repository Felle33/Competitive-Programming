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
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pll>> adj(n);
    vll dis(n, INF);
    rep(i, m) {
        int a, b, w;
        cin >> a >> b >> w;
        a--,b--;
        adj[a].push_back({b, w});
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(mp(0, 0));
    dis[0] = 0;
    vector<bool> visited(n);
    while(!pq.empty()) {
        pll node = pq.top();
        pq.pop();

        if(visited[node.s]) continue;
        visited[node.s] = true;
        for(pll near : adj[node.s]) {
            if(node.f + near.s < dis[near.f]) {
                dis[near.first] = node.f + near.s;
                pq.push(mp(node.f + near.s, near.f));
            }
        }
    }
    
    rep(i, n) {
        cout << dis[i] << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}