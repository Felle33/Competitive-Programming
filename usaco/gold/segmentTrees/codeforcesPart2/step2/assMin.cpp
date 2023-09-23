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
#include <array>

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

struct SegmentTree {
    int size;
    vector<ll> tree;
    vector<ll> op;

    ll NEUTRAL_ELEMENT = LONG_LONG_MAX - 1;
    ll NOP = LONG_LONG_MAX;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
        op.resize(2 * size, NOP);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x] = numbers[lx];
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void propagate(int x, int lx, int rx) {
        if(rx - lx == 1 || op[x] == NOP) return;
        tree[2 * x + 1] = op[x];
        tree[2 * x + 2] = op[x];
        op[2 * x + 1] = op[x];
        op[2 * x + 2] = op[x];
        op[x] = NOP;
    }

    void ass(int l_query, int r_query, ll value, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query) {
            tree[x] = value;
            op[x] = value;
            return;
        }

        int mid = (lx + rx) / 2;
        ass(l_query, r_query, value, 2 * x + 1, lx, mid);
        ass(l_query, r_query, value, 2 * x + 2, mid, rx);
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void ass(int l, int r, ll v) {
        ass(l, r, v, 0, 0, size);
    }

    ll mini(int l_query, int r_query, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) {
            return tree[x];
        }

        int mid = (lx + rx) / 2;
        ll s1 = mini(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = mini(l_query, r_query, 2 * x + 2, mid, rx);
        return min(s1, s2);
    }

    ll mini(int l, int r) {
        return mini(l, r, 0, 0, size);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;
    int n, m;
    cin >> n >> m;

    SegmentTree segmentTree(n);
    vll a(n);
    segmentTree.build(a);

    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            ll l, r, v;
            cin >> l >> r >> v;
            segmentTree.ass(l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << segmentTree.mini(l, r) << '\n';
        }
    }
}