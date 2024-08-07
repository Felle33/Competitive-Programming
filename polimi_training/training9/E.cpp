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

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct Edge {
    int from, to;
    ll capacity, cost;
};

struct MaxFlowMinCost {
    vvi adj;
    vector<vll> cost, capacity;

    void shortest_paths(int n, int v0, vector<ll>& d, vector<int>& p) {
        d.assign(n, INF);
        d[v0] = 0;
        vector<bool> inq(n, false);
        queue<int> q;
        q.push(v0);
        p.assign(n, -1);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int v : adj[u]) {
                if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                    d[v] = d[u] + cost[u][v];
                    p[v] = u;
                    if (!inq[v]) {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    // N number of nodes
    // edges
    // K = maxFlow to reach
    // s = source
    // t = sink
    int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
        adj.assign(N, vector<int>());
        cost.assign(N, vector<ll>(N, 0));
        capacity.assign(N, vector<ll>(N, 0));

        for (Edge e : edges) {
            adj[e.from].push_back(e.to);
            adj[e.to].push_back(e.from);
            cost[e.from][e.to] = e.cost;
            cost[e.to][e.from] = -e.cost;
            capacity[e.from][e.to] = e.capacity;
        }

        int flow = 0;
        int cost = 0;
        vll d;
        vi p;
        while (flow < K) {
            shortest_paths(N, s, d, p);
            if (d[t] == INF)
                break;

            // find max flow on that path
            ll f = K - flow;
            int cur = t;
            while (cur != s) {
                f = min(f, capacity[p[cur]][cur]);
                cur = p[cur];
            }

            // apply flow
            flow += f;
            cost += f * d[t];
            cur = t;
            while (cur != s) {
                capacity[p[cur]][cur] -= f;
                capacity[cur][p[cur]] += f;
                cur = p[cur];
            }
        }

        if (flow < K)
            return -1;
        else
            return cost;
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vector<pii> constr(n + 1, {1, n});
    vector<Edge> edges;

    rep(i, q) {
        int t, a, b, x;
        cin >> t >> a >> b >> x;
        
        if(t == 1) {
            for(int j = a; j <= b; j++) {
                constr[j].first = max(constr[j].first, x);
            }
        } else {
            for(int j = a; j <= b; j++) {
                constr[j].second = min(constr[j].second, x);
            }
        }
    }

    for(pii& con : constr) {
        if(con.first > con.second) {
            cout << -1 << '\n';
            return;
        }
    }

    MaxFlowMinCost maxFlowMinCost;
    int source = 0;
    int sink = 2 * n + 1;

    // from source to numbers
    for(int i = 1; i <= n; i++) {
        for(ll cost = 1; cost <= 1 + 2 * n; cost += 2) {
            edges.push_back({source, i, 1, cost});
        }
    }

    // from numbers to indeces
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            pii& con = constr[j];
            if(i >= con.first && i <= con.second) {
                edges.push_back({i, j + n, 1, 0});
            }
        }
    }

    // from indeces to sink
    for(int i = n + 1; i <= 2 * n; i++) {
        edges.push_back({i, sink, 1, 0});
    }

    cout << maxFlowMinCost.min_cost_flow(2 * n + 2, edges, n, 0, 2 * n + 1) << '\n';
    vi ans(n);

    for(int i = 1; i <= n; i++) {
        for(int to : maxFlowMinCost.adj[i]) {
            if(maxFlowMinCost.capacity[i][to] == 0) {
                ans[to - n - 1] = i;
            }
        }
    }

    for(int x : ans) cout << x << ' ';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}