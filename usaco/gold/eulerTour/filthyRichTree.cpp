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
typedef long double ld;

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

struct SegmentTree {
    int size;
    vector<ld> tree;

    ld NEUTRAL_ELEMENT = 0.0;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
    }

    void set(int i, ld v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = v;
            return;
        }

        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set(int i, ld v) {
        set(i, v, 0, 0, size);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    ld sum(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        ld s1 = sum(l_query, r_query, 2 * x + 1, lx, mid);
        ld s2 = sum(l_query, r_query, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    ld sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

vvi adj;
int timer = 0;
vi start, finish;

void eulerTour(int node, int p) {
    start[node] = timer++;
    for(int to : adj[node]) {
        if(to != p) {
            eulerTour(to, node);
        }
    }
    finish[node] = timer;
}

void solve(){
    int n; cin >> n;
    adj = vvi(n);
    start = vi(n);
    finish = vi(n);

    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    eulerTour(0, -1);
    SegmentTree sgt(n);

    int q; cin >> q;
    rep(i, q) {
        int t;
        cin >> t;

        if(t == 1) {
            // set
            int a; ld b;
            cin >> a >> b;
            a--;
            sgt.set(start[a], log(b));
        } else {
            int a, b; cin >> a >> b;
            a--, b--;
            // calculate
            ld sumA = sgt.sum(start[a], finish[a]);
            ld sumB = sgt.sum(start[b], finish[b]);

            double ans = sumA - sumB;
            
            if(ans >= log(1e9)) {
                cout << 1e9 << '\n';
            } else {
                cout << exp(ans) << '\n';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}