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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

const int MAX_N = 2e5;

vi adj[MAX_N];
int subtreeSize[MAX_N];
int parent[MAX_N];
queue<int> q;

void dfs(int u, int p) {
    parent[u] = p;
    subtreeSize[u] = 1;
    for(int to : adj[u]) {
        if(to != p) {
            dfs(to, u);
            subtreeSize[u] += subtreeSize[to];
        }
    }
}

int centroid(int entryPoint) {
    dfs(entryPoint, entryPoint);
    
    int centroid = entryPoint;
    int bestSize = subtreeSize[entryPoint];
    q.push(entryPoint);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int size = subtreeSize[entryPoint] - subtreeSize[u];

        for(int to : adj[u]) {
            if(to != parent[u]) {
                q.push(to);
                size = max(size, subtreeSize[to]);
            }
        }

        if(bestSize > size) {
            bestSize = size;
            centroid = u;
        }
    }

    return centroid;
}

void solve(){
    int n; cin >> n;
    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    cout << centroid(0) + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}