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
    for(int to : adj_rev[node]) {
        if(!visited[to]){
            visited[to] = 1;
            dfs_2(to);
        }
    }
}

void kosaraju() {
    visited = vector<bool>(n);
    labels = vi(n);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) dfs_post(i);
    }

    for(int i = 0; i < n; i++) visited[i] = 0;

    while(!stack_nodes.empty()) {
        int start = stack_nodes.top();
        stack_nodes.pop();

        if(!visited[start]) {
            dfs_2(start);
        }
    }

    vvi scc(l + 1);
    set<pii> edges;

    for(int i = 0; i < n; i++) {
        for(int to : adj[i]) {
            if(labels[i] != labels[to]) {
                if(edges.count(mp(labels[i], labels[to])) == 0) {
                    edges.insert(mp(labels[i], labels[to]));
                    scc[labels[i]].push_back(labels[to]);
                }
            }
        }
    }

    for(int i = 0; i <= l; i++) {
        cout << "The connected component " << i << " composed by ";
        for(int j = 0; j < n; j++) {
            if(labels[j] == i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }

    cout << "\nARCS\n";

    for(int i = 0; i <= l; i++) {
        cout << "From " << i << ": ";

        for(int to : scc[i]) {
            cout << to << " ";
        }
        cout << '\n';
    }
}

void solve(){
    cin >> n >> m;

    adj = vvi(n);
    adj_rev = vvi(n);

    rep(i, m) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj_rev[b].pb(a);
    }

    kosaraju();

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}

/* Test case
9 11
0 1
1 2
2 0
3 2
2 4
4 8
4 5
5 6
5 7
6 7
7 4
*/