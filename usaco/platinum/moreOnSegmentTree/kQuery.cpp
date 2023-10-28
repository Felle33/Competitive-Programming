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
    vector<ll> range;
};

struct SegmentTree {
    int size;
    vector<Vertex> tree;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    void calculateOnesRange(int x, int lx, int rx) {
        
    }

    void buildRange(int x, int lx, int rx) {
        Vertex left = tree[2 * x + 1];
        Vertex right = tree[2 * x + 2];
        merge(all(left.range), all(right.range), back_inserter(tree[x].range));
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x].range.push_back(numbers[lx]);
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        buildRange(x, lx, rx);
    }

    ll calculateMajors(int x, ll value) {
        auto it = upper_bound(all(tree[x].range), value);
        return (tree[x].range.end() - it);
    }

    ll majors(int l_query, int r_query, ll value, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return 0;
        if(l_query <= lx && rx <= r_query) {
            return calculateMajors(x, value);
        }
        int mid = (lx + rx) / 2;
        ll s1 = majors(l_query, r_query, value, 2 * x + 1, lx, mid);
        ll s2 = majors(l_query, r_query, value, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    ll majors(int l, int r, ll value) {
        return majors(l, r, value, 0, 0, size);
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
        ll l, r, v; cin >> l >> r >> v;
        l--;
        cout << sgt.majors(l, r, v) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}