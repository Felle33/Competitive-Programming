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
//bool visited[MAX_N];
//vector<int> to_remove_visited;
int mx_depth;

int parent[MAX_N];
ll centroid_array[MAX_N];
//ll subtree_array[MAX_N];

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

void get_cnt(int node, int parent, bool filling, int depth = 1) {
	if (depth > k) return;

	mx_depth = max(mx_depth, depth);

	if (filling) centroid_array[depth]++;
	else ans += centroid_array[k - depth];
	for (int i : adj[node])
		if (!removed[i] && i != parent) get_cnt(i, node, filling, depth + 1);
}

void find_centroid(int entryPoint) {
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
    mx_depth = 0;
    for(int to : adj[centroid]) {
        if(!removed[to]) {
            get_cnt(to, centroid, false);
            get_cnt(to, centroid, true);
        }
    }
    
    for(int i = 1; i <= mx_depth; i++) {
        centroid_array[i] = 0;
    }

    for(int to : adj[centroid]) {
        if(!removed[to]) {
            find_centroid(to);
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

    find_centroid(0);

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

ans = 10
*/