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
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct Vertex {
    ll sum;
    ll onesInterval[32];
    ll op;
};

struct SegmentTree {
    int size;
    vector<Vertex> tree;

    ll NOP = LLONG_MAX;
    Vertex NEUTRAL_ELEMENT = {0, {0}, NOP};

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    void calculateOnesRange(int x, int lx, int rx) {
        Vertex left = tree[2 * x + 1];
        Vertex right = tree[2 * x + 2];
        for(int i = 0; i < 32; i++) {
            tree[x].onesInterval[i] = left.onesInterval[i] + right.onesInterval[i];
        }
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                int v = numbers[lx];
                tree[x].sum = numbers[lx];
                for(int i = 0; i < 32; i++) {
                    tree[x].onesInterval[i] = 0;
                    if((1 << i) & v) tree[x].onesInterval[i] = 1;
                }
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        calculateOnesRange(x, lx, rx);
        tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum;
    }

    void modifySegment(ll v, int x, int lx, int rx) {
        tree[x].op = (tree[x].op == NOP ? v : tree[x].op ^ v);
        for(int i = 0; i < 32; i++) {
            if(v & (1 << i)) {
                ll minu = tree[x].onesInterval[i] * (1 << i);
                ll addi = (rx - lx - tree[x].onesInterval[i]) * (1 << i);
                tree[x].sum += (addi - minu);
                tree[x].onesInterval[i] = (rx - lx - tree[x].onesInterval[i]);
            }
        }
    }

    void propagate(int x, int lx, int rx) {
        if(tree[x].op == NOP || rx - lx == 1) return;
        int mid = (rx + lx) / 2;
        modifySegment(tree[x].op, 2 * x + 1, lx, mid);
        modifySegment(tree[x].op, 2 * x + 2, mid, rx);
        tree[x].op = NOP;
    }

    void xorBit(int l_query, int r_query, ll v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query){
            modifySegment(v, x, lx, rx);
            return;
        }

        int m = (lx + rx) / 2;
        xorBit(l_query, r_query, v, 2 * x + 1, lx, m);
        xorBit(l_query, r_query, v, 2 * x + 2, m, rx);
        calculateOnesRange(x, lx, rx);
        tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum;
    }

    void xorBit(int l_query, int r_query, ll v) {
        xorBit(l_query, r_query, v, 0, 0, size);
    }

    ll sum(int l_query, int r_query, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return 0;
        if(l_query <= lx && rx <= r_query) return tree[x].sum;
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
    int n; cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    SegmentTree sgt(n);
    sgt.build(a);
    int q; cin >> q;
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r; cin >> l >> r;
            l--;
            cout << sgt.sum(l, r) << '\n';
        } else {
            ll l, r, x; cin >> l >> r >> x;
            l--;
            sgt.xorBit(l, r, x);
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