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
const ll INF = 1e17;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct SegmentTree {
    int size;
    vector<ll> tree, op;

    ll NEUTRAL_ELEMENT = 0;
    ll NOP = INF;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
        op.resize(2 * size, NOP);
    }

    void propagate(int x, int lx, int rx) {
        if(op[x] == NOP || rx - lx == 1) return;
        int mid = (rx + lx) / 2;
        tree[2 * x + 1] += op[x] * (mid - lx);
        tree[2 * x + 2] += op[x] * (rx - mid);
        op[2 * x + 1] = (op[2 * x + 1] == NOP ? op[x] : op[2 * x + 1] + op[x]);
        op[2 * x + 2] = (op[2 * x + 2] == NOP ? op[x] : op[2 * x + 2] + op[x]);
        op[x] = NOP;
    }

    void add(int l_query, int r_query, ll v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query){
            tree[x] += (rx - lx) * v;
            op[x] = (op[x] == NOP ? v : op[x] + v);
            return;
        }

        int m = (lx + rx) / 2;
        add(l_query, r_query, v, 2 * x + 1, lx, m);
        add(l_query, r_query, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void add(int l_query, int r_query, ll v) {
        add(l_query, r_query, v, 0, 0, size);
    }

    ll sum(int l_query, int r_query, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        ll s1 = sum(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = sum(l_query, r_query, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    SegmentTree sgt(n);
    while(q--) {
        int c; cin >> c;
        if(c == 0) {
            ll l, r, v; cin >> l >> r >> v;
            l--;
            sgt.add(l, r, v);
        } else {
            ll l, r; cin >> l >> r;
            l--;
            cout << sgt.sum(l, r) << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}