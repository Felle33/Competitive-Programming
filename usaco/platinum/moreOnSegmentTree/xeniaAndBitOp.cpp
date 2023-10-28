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
const ll LL_MAX = 9223372036854775807;

struct SegmentTree {
    int size;
    vector<ll> tree;

    ll NEUTRAL_ELEMENT_OR = 0;
    ll NEUTRAL_ELEMENT_XOR = LL_MAX;
    int mode;

    SegmentTree(int n, int _mode) {
        mode = _mode;
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size);
    }

    // mode = 1 => last op is a OR
    // mode = 0 => last op is a XOR
    void build(vector<ll>& numbers){
        build(numbers, mode, 0, 0, size);
    }

    void build(vector<ll>& numbers, int modeRec, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x]= numbers[lx];
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, !modeRec, 2 * x + 1, lx, mid);
        build(numbers, !modeRec, 2 * x + 2, mid, rx);
        tree[x] = (modeRec == 1 ? tree[2 * x + 1] | tree[2 * x + 2] : tree[2 * x + 1] ^ tree[2 * x + 2]);
    }

    void set(int i, ll value, int modeRec, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = value;
            return;
        }
        int mid = (lx + rx) / 2;
        if(i < mid) {
            set(i, value, !modeRec, 2 * x + 1, lx, mid);
        } else {
            set(i, value, !modeRec, 2 * x + 2, mid, rx);
        }

        tree[x] = (modeRec == 1 ? tree[2 * x + 1] | tree[2 * x + 2] : tree[2 * x + 1] ^ tree[2 * x + 2]);
    }

    void set(int i, ll value) {
        return set(i, value, mode, 0, 0, size);
    }

    ll calc() {
        return tree[0];
    }
};

int modeOp(int x) {
    for(int i = 0; i < 32; i++) {
        if(x & (1 << i)) {
            return i % 2 == 1 ? 1 : 0;
        }
    }
    return -1;
}

void solve(){
    int n, q; cin >> n >> q;
    n = 1 << n;
    vll a(n);
    rep(i, n) cin >> a[i];
    SegmentTree sgt(n, modeOp(n));
    sgt.build(a);
    while(q--) {
        ll i, v; cin >> i >> v;
        i--;
        sgt.set(i, v);
        cout << sgt.calc() << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}