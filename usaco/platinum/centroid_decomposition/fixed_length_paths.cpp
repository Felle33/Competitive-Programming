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
int n, k;

vi adj[MAX_N];
int subtreeSize[MAX_N];
bool removed[MAX_N];
bool visited[MAX_N];
vector<int> to_remove_visited;

int parent[MAX_N];
ll centroid_array[MAX_N];
ll subtree_array[MAX_N];

queue<int> q;
ll ans;

void calc_subtree_size(int u, int p) {
    parent[u] = p;
    subtreeSize[u] = 1;
    for(int to : adj[u]) {
        if(to != p && !removed[to]) {
            calc_subtree_size(to, u);
            subtreeSize[u] += subtreeSize[to];
        }
    }
}

void bfs(int start) {
    int distance = 1;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int size = q.size();

        while(size--) {
            int u = q.front();
            q.pop();
            subtree_array[distance]++;

            for(int to : adj[u]) {
                if(!removed[to] && !visited[to]) {
                    q.push(to);
                    visited[to] = 1;
                    to_remove_visited.pb(to);
                }
            }
        }
        distance++;
    }
}

void find_centroid(int entryPoint, int level) {
    calc_subtree_size(entryPoint, entryPoint);

    int centroid = entryPoint;
    int bestSize = subtreeSize[entryPoint];
    q.push(entryPoint);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int size = subtreeSize[entryPoint] - subtreeSize[u];
        for(int to : adj[u]) {
            if(to != parent[u] && !removed[to]) {
                q.push(to);
                size = max(size, subtreeSize[to]);
            }
        }

        if(bestSize > size) {
            bestSize = size;
            centroid = u;
        }
    }

    /*printf("After having as centroid %d, the vector ancestor is built in this way:\n", centroid);
    for(int node = 0; node < n; node++) {
        printf("Node %d: ", node);
        for(auto& [anc, dis] : ancestors[node]) {
            printf("Ancestor %d, distance %d ; ", anc, dis);
        }
        printf("\n");
    }
    printf("\n\n");*/

    removed[centroid] = 1;

    centroid_array[0] = 1;
    for(int to : adj[centroid]) {
        if(!removed[to]) {
            bfs(to);

            for(int i = 1; i <= k && subtree_array[i] > 0 ; i++) {
                ans += subtree_array[i] * centroid_array[k - i];
            }

            for(int i = 1; subtree_array[i] > 0; i++) {
                centroid_array[i] += subtree_array[i];
                subtree_array[i] = 0;
            }
        }
    }
    
    for(int i = 1; centroid_array[i] > 0; i++) {
        centroid_array[i] = 0;
    }

    for(int u : to_remove_visited) {
        visited[u] = 0;
    }
    to_remove_visited.clear();

    for(int to : adj[centroid]) {
        if(!removed[to]) {
            find_centroid(to, level + 1);
        }
    }
}

void solve(){
    cin >> n >> k;
    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    find_centroid(0, 0);

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}

/*
10 2
2 1
3 1
4 3
5 4
6 5
7 1
8 6
9 2
10 6
*/