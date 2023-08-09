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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9 + 1;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct SegmentTree {
    int size;
    // int is the number, and ll is the count
    vector<pair<int, ll>> tree;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, {INF, 1});
    }

    void build(vector<ll>& numbers, int n){
        build(numbers, 0, 0, size);
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[lx] = {numbers[lx], 1};
            }
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);

        if(tree[2 * x + 1].first < tree[2 * x + 2].first) {
            tree[x].first = tree[2 * x + 1].first;
            tree[x].second = tree[2 * x + 1].second;
        } else if (tree[2 * x + 1].first > tree[2 * x + 2].first) {
            tree[x].first = tree[2 * x + 2].first;
            tree[x].second = tree[2 * x + 2].second;
        } else {
            tree[x].first = tree[2 * x + 1].first;
            tree[x].second = tree[2 * x + 1].second + tree[2 * x + 2].second;
        }
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = {v, 1};
            return;
        }

        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }

        if(tree[2 * x + 1].first < tree[2 * x + 2].first) {
            tree[x].first = tree[2 * x + 1].first;
            tree[x].second = tree[2 * x + 1].second;
        } else if (tree[2 * x + 1].first > tree[2 * x + 2].first) {
            tree[x].first = tree[2 * x + 2].first;
            tree[x].second = tree[2 * x + 2].second;
        } else {
            tree[x].first = tree[2 * x + 1].first;
            tree[x].second = tree[2 * x + 1].second + tree[2 * x + 2].second;
        }
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    pair<int, ll> minimum(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return {INF, 1};
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        pair<int, ll> pm1 = minimum(l_query, r_query, 2 * x + 1, lx, mid);
        pair<int, ll> pm2 = minimum(l_query, r_query, 2 * x + 2, mid, rx);

        if(pm1.first < pm2.first) {
            return pm1;
        } else if (pm1.first > pm2.first) {
            return pm2;
        } 

        return {pm1.first, pm1.second + pm2.second};
    }

    pair<int, ll> minimum(int l, int r) {
        return minimum(l, r, 0, 0, size);
    }
};
 
int main(){
    int n, m;
    cin >> n >> m;

    SegmentTree segmentTree(n);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        segmentTree.set(i, a);
    }

    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int i, v;
            cin >> i >> v;
            segmentTree.set(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            pair<int, ll> res = segmentTree.minimum(l, r);
            cout << res.first << " " << res.second << '\n';
        }
    }
}