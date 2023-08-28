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

#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define mp make_pair
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

// TODO DA RIGUARDAREEEEEEEEEEEE
struct SegmentTree {
    int size;
    // pair in which the first number is the minimum and the second is
    // the number to add with the mass operation
    ll NOP = LLONG_MAX - 1;
    ll NEUTRAL_ELEMENT = LLONG_MAX;
    vector<ll> values, operations;
 
    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        values.resize(2 * size, LLONG_MAX);
        operations.resize(2 * size, NOP);
    }
 
    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }
 
    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x] = mp(numbers[lx], 0);
            }
            return;
        }
 
        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        tree[x] = mp(min(tree[2 * x + 1].first, tree[2 * x + 2].first), 0LL);
    }

    ll modify_op(ll a, ll b) {
        if(b == NOP) return a;
        return b;
    }

    ll calc_op(ll a, ll b) {
        return min(a, b);
    }

    void apply_op(ll &a, ll b) {
        a = modify_op(a, b);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) return;
        apply_op(values[2 * x + 1], operations[x]);
        apply_op(values[2 * x + 2], operations[x]);
        operations[x] = NOP;
    }
 
    void add(int l_query, int r_query, int v, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query){
            tree[x].first += v;
            tree[x].second += v;
            return;
        }
 
        int mid = (lx + rx) / 2;
        add(l_query, r_query, v, 2 * x + 1, lx, mid);
        add(l_query, r_query, v, 2 * x + 2, mid, rx);
    }
 
    void add(int l, int r, int v) {
        add(l, r, v, 0, 0, size);
    }
 
    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    ll minimum(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return INF;
        if(l_query <= lx && rx <= r_query) return tree[x].first;
        int mid = (lx + rx) / 2;
        ll s1 = minimum(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = minimum(l_query, r_query, 2 * x + 2, mid, rx);
        return min(s1, s2) + tree[x].second;
    }
 
    ll minimum(int l, int r) {
        return minimum(l, r, 0, 0, size);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
 
    SegmentTree segmentTree(n);
    vector<ll> nums(n);
    segmentTree.build(nums);
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            segmentTree.add(l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << segmentTree.minimum(l, r) << '\n';
        }
    }
}