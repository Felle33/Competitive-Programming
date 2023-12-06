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
#include <stack>

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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n, m;
int l = -1;

vvi adj;
vvi adj_rev;

stack<int> stack_nodes;
vector<bool> visited;
vector<int> labels;

vi c;
vll coins;
vvi scc;

vll memo;

void dfs_post(int node) {
    visited[node] = 1;
    for(int to : adj[node]) {
        if(!visited[to]) {
            dfs_post(to);
        }
    }
    stack_nodes.push(node);
}

void dfs_2(int node) {
    if(!visited[node]){
        visited[node] = 1;
        ++l;
    }

    labels[node] = l;
    for(int& to : adj_rev[node]) {
        if(!visited[to]){
            visited[to] = 1;
            dfs_2(to);
        }
    }
}

void kosaraju() {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) dfs_post(i);
    }

    fill(all(visited), 0);

    while(!stack_nodes.empty()) {
        int start = stack_nodes.top();
        stack_nodes.pop();

        if(!visited[start]) {
            dfs_2(start);
        }
    }

    scc = vvi(l + 1);
    set<pii> edges;

    for(int i = 0; i < n; i++) {
        for(int& to : adj[i]) {
            if(labels[i] != labels[to]) {
                if(edges.count(mp(labels[i], labels[to])) == 0) {
                    edges.insert(mp(labels[i], labels[to]));
                    scc[labels[i]].push_back(labels[to]);
                }
            }
        }
    }
}

ll dfs_max_coins(int node) {
    if(node == labels[n - 1]) return coins[labels[n - 1]];
    if(memo[node] != -1) return memo[node];

    ll max_ans = -2;
    for(int& to : scc[node]) {
        max_ans = max(max_ans, dfs_max_coins(to));
    }

    return max_ans == -2 ? -2 : max_ans + coins[node];
}

void solve(){
    cin >> n >> m;

    adj = vvi(n);
    adj_rev = vvi(n);
    c = vi(n);
    labels = vi(n);
    visited = vector<bool>(n);

    rep(i, n) cin >> c[i];

    rep(i, m) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj_rev[b].pb(a);
    }

    kosaraju();

    memo = vll(l + 1, -1);
    coins = vll(l + 1);
    for(int i = 0; i < n; i++) {
        coins[labels[i]] += c[i];
    }

    cout << dfs_max_coins(labels[0]) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}