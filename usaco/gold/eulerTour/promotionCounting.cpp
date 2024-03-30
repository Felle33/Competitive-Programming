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

struct node {
    vector<int> nums;
};

struct SegmentTree {
    int size;
    vector<node> tree;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size);
    }

    void build(vector<int>& numbers){
        build(numbers, 0, 0, size);
    }

    void merge(vi& res, vi& a, vi& b) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        for(; i < n && j < m; ) {
            if(a[i] < b[j]) {
                res.push_back(a[i]);
                i++;
            } else {
                res.push_back(b[j]);
                j++;
            }
        }

        while(i < n) {
            res.push_back(a[i]);
            i++;
        }

        while(j < m) {
            res.push_back(b[j]);
            j++;
        }
    }

    void build(vector<int>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x].nums.push_back(numbers[lx]);
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        merge(tree[x].nums, tree[2 * x + 1].nums, tree[2 * x + 2].nums);
    }

    ll search(vi& a, int n) {
        return a.end() - upper_bound(all(a), n);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    ll upper_than(int l_query, int r_query, int x, int lx, int rx, int n) {
        if(l_query >= rx || r_query <= lx) return 0;
        if(l_query <= lx && rx <= r_query) return search(tree[x].nums, n);
        int mid = (lx + rx) / 2;
        ll s1 = upper_than(l_query, r_query, 2 * x + 1, lx, mid, n);
        ll s2 = upper_than(l_query, r_query, 2 * x + 2, mid, rx, n);
        return s1 + s2;
    }

    ll upper_than(int l, int r, int n) {
        return upper_than(l, r, 0, 0, size, n);
    }
};

vvi adj;
int timer;
vi start, finish;
vi order;

void eulerTour(int node, int p) {
    start[node] = timer++;
    order.pb(node);
    for(int to : adj[node]) {
        if(to != p) {
            eulerTour(to, node);
        }
    }
    finish[node] = timer;
}

void solve(){
    int n; cin >> n;
    vi prof(n);
    adj = vvi(n);
    start = vi(n);
    finish = vi(n);

    rep(i, n) cin >> prof[i];

    rep(i, n - 1) {
        int a; cin >> a;
        a--;
        adj[i + 1].pb(a);
        adj[a].pb(i + 1);
    }

    eulerTour(0, -1);
    SegmentTree sgt(n);
    vi elements(n);

    for(int i = 0; i < n; i++) elements[i] = prof[order[i]];
    sgt.build(elements);

    rep(i, n) {
        cout << sgt.upper_than(start[i], finish[i], prof[i]) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
    solve();
}