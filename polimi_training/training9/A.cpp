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
        return a.end() - lower_bound(all(a), n);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    ll more_than(int l_query, int r_query, int x, int lx, int rx, int n) {
        if(l_query >= rx || r_query <= lx) return 0;
        if(l_query <= lx && rx <= r_query) return search(tree[x].nums, n);
        int mid = (lx + rx) / 2;
        ll s1 = more_than(l_query, r_query, 2 * x + 1, lx, mid, n);
        ll s2 = more_than(l_query, r_query, 2 * x + 2, mid, rx, n);
        return s1 + s2;
    }

    ll more_than(int l, int r, int n) {
        return more_than(l, r, 0, 0, size, n);
    }
};

void solve(){
    int n; cin >> n;
    vi a(n);
    int maxN = 2e5 + 1;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        a[i] = min(maxN, tmp);
    }

    SegmentTree sgt(n);
    sgt.build(a);

    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans += sgt.more_than(i + 1, min(a[i], n), i + 1);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}