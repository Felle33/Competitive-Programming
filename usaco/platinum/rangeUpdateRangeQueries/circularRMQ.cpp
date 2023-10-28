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
const ll LL_MAX = 9223372036854775807LL;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct SegmentTree {
    int size;
    vector<ll> tree, op;

    ll NEUTRAL_ELEMENT = LL_MAX;
    ll NOP = LL_MAX - 1;
    int n;

    SegmentTree(int _n) {
        n = _n;
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
        if(op[x] == NOP || rx - lx == 1) return;
        tree[2 * x + 1] += op[x];
        tree[2 * x + 2] += op[x];
        op[2 * x + 1] = (op[2 * x + 1] == NOP ? op[x] : op[2 * x + 1] + op[x]);
        op[2 * x + 2] = (op[2 * x + 2] == NOP ? op[x] : op[2 * x + 2] + op[x]);
        op[x] = NOP;
    }

    void add(int l_query, int r_query, ll v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query){
            tree[x] += v;
            op[x] = (op[x] == NOP ? v : op[x] + v);
            return;
        }

        int m = (lx + rx) / 2;
        add(l_query, r_query, v, 2 * x + 1, lx, m);
        add(l_query, r_query, v, 2 * x + 2, m, rx);
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    // [l_query, r_query] included
    void add(int l_query, int r_query, ll v) {
        if(l_query <= r_query) {
            add(l_query, r_query + 1, v, 0, 0, size);
        } else {
            add(l_query, n, v, 0, 0, size);
            add(0, r_query + 1, v, 0, 0, size);
        }
    }

    ll mini(int l_query, int r_query, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        ll s1 = mini(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = mini(l_query, r_query, 2 * x + 2, mid, rx);
        return min(s1, s2);
    }

    ll mini(int l_query, int r_query) {
        if(l_query <= r_query) {
            return mini(l_query, r_query + 1, 0, 0, size);
        }

        ll s1 = mini(l_query, n, 0, 0, size);
        ll s2 = mini(0, r_query + 1, 0, 0, size);
        return min(s1, s2);
    }
};

void solve(){
    int n; cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    SegmentTree sgt(n);
    sgt.build(a);
    int q; cin >> q;
    q++;
    while(q--) {
        string input;
        getline(cin, input);

        istringstream iss(input);
        vector<ll> numbers;
        ll num;

        while (iss >> num) {
            numbers.push_back(num);
        }

        if(numbers.size() == 2) {
            cout << sgt.mini(numbers[0], numbers[1]) << '\n';
        } else if(numbers.size() == 3) {
            sgt.add(numbers[0], numbers[1], numbers[2]);
        }
        numbers.erase(all(numbers));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}