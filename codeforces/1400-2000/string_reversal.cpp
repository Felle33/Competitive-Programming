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
#define FELLE ios_base::sync_with_stdio(false); cin.tie(NULL); std::cout.precision(10); cout << std::fixed;

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
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

template <typename T>
struct SegmentTree {
    int size;
    vector<T> tree;

    T NEUTRAL_ELEMENT = 0;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
    }

    void add(int i, T v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] += v;
            return;
        }

        int m = (lx + rx) / 2;
        if(i < m) {
            add(i, v, 2 * x + 1, lx, m);
        } else {
            add(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void add(int i, T v) {
        add(i, v, 0, 0, size);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    T sum(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        T s1 = sum(l_query, r_query, 2 * x + 1, lx, mid);
        T s2 = sum(l_query, r_query, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    T sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    string rev = s;
    reverse(all(rev));

    vector<vector<int>> letters(30);
    vi pointers(30);
    vi a(n);

    for(int i = 0; i < n; i++) {
        letters[s[i] - 'a'].push_back(i);
    }

    for(int i = 0; i < n; i++) {
        int cell = rev[i] - 'a';
        int p = pointers[cell];
        pointers[cell]++;
        a[letters[cell][p]] = i + 1;
    }

    SegmentTree<ll> sgt(n + 1);
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        ans += sgt.sum(0, a[i]);
        sgt.add(a[i], 1ll);
    }

    cout << ans << "\n";
}

int main(){
    FELLE
    solve();
}