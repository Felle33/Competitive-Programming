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
    vector<ll> tree;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, INF);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = v;
            return;
        }

        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    ll sum(int l_query, int r_query, int x, int lx, int rx, int p) {
        if(l_query >= rx || r_query <= lx || tree[x] > p) return 0;
        if(rx - lx == 1) {
            tree[x] = INF;
            return 1;
        }

        int mid = (lx + rx) / 2;
        ll s1 = sum(l_query, r_query, 2 * x + 1, lx, mid, p);
        ll s2 = sum(l_query, r_query, 2 * x + 2, mid, rx, p);
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
        return s1 + s2;
    }

    ll sum(int l, int r, int p) {
        return sum(l, r, 0, 0, size, p);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    SegmentTree sgt(n);
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int i, v;
            cin >> i >> v;
            sgt.set(i, v);
        } else {
            int l, r, p;
            cin >> l >> r >> p;
            cout << sgt.sum(l, r, p) << '\n';
        }
    }
}