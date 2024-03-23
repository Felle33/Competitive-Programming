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

const int MAX_N = 1002;
int start;
int end_point;

vi adj[MAX_N];
ll cap[MAX_N][MAX_N];
bool visited[MAX_N];

ll dfs(int node, int sink, ll minCapacity) {
    if(node == sink) return minCapacity;
    visited[node] = 1;
    
    for(int to : adj[node]) {
        if(cap[node][to] > 0 && !visited[to]) {
            ll res = dfs(to, sink, min(minCapacity, cap[node][to]));
            if(res > 0) {
                cap[node][to] -= res;
                cap[to][node] += res;
                return res;
            }
        }
    }

    return 0;
}

ll ford_fulkerson(int source, int sink) {
    ll result = 0;
    while(1) {
        ll currFlow  = dfs(source, sink, INF);
        result += currFlow;

        if(currFlow  == 0) break;
        for(int i = 0; i < MAX_N; i++) visited[i] = 0;
    }

    return result;
}

void compute_pairs(vector<pii>& pairs) {
    for(int to : adj[end_point]) {
        if(cap[end_point][to] > 0) {
            int fem = to;
            for(int boy : adj[fem]) {
                if(cap[fem][boy] > 0) {
                    pairs.pb({boy, fem});
                    break;
                }
            }
        }
    }
}

void solve(){
    int b, g, k;
    cin >> b >> g >> k;
    
    start = 0, end_point = b + g + 1;
    map<int, int> map_girl_id;
    map<int, int> map_id_girl;
    for(int i = 1, key = b + 1; i <= g; i++, key++) {
        map_girl_id[i] = key;
        map_id_girl[key] = i;
    }

    for(int i = 1; i <= b; i++) {
        adj[0].pb(i);
        adj[i].pb(0);
        cap[0][i] = 1;
    }

    for(int i = 1, key = b + 1; i <= g; i++, key++) {
        adj[key].pb(end_point);
        adj[end_point].pb(key);
        cap[key][end_point] = 1;
    }

    rep(i, k) {
        int a, b; cin >> a >> b;
        int g = map_girl_id[b];
        adj[a].pb(g);
        adj[g].pb(a);
        cap[a][g] = 1;
    }

    cout << ford_fulkerson(0, end_point) << '\n';

    vector<pii> pairs;
    compute_pairs(pairs);

    for(pii& p : pairs) {
        cout << p.first << " " << map_id_girl[p.second] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}