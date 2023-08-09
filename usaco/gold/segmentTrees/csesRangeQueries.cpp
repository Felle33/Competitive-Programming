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
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";
 
struct SegmentTree {
    int size;
    vector<ll> tree;
 
    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, 0LL);
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
    }
 
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
 
    void add(int l_query, int r_query, int v, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query){
            tree[x] += v;
            return;
        }
 
        int mid = (lx + rx) / 2;
        add(l_query, r_query, v, 2 * x + 1, lx, mid);
        add(l_query, r_query, v, 2 * x + 2, mid, rx);
    }
 
    void add(int l, int r, int v) {
        add(l, r, v, 0, 0, size);
    }
 
    ll get(int i, int x, int lx, int rx) {
        if(rx - lx == 1) return tree[x];
 
        int mid = (lx + rx) / 2;
        ll res;
        if(i < mid) {
            res = get(i, 2 * x + 1, lx, mid);
        } else {
            res = get(i, 2 * x + 2, mid, rx);
        }
 
        return res + tree[x];
    }
 
    ll get(int i) {
        return get(i, 0, 0, size);
    }
 
    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    ll sum(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return 0;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        ll s1 = sum(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = sum(l_query, r_query, 2 * x + 2, mid, rx);
        return s1 + s2;
    }
 
    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;

    vector<ll> nums(n);
    rep(i, n) {
        cin >> nums[i];
    }
 
    SegmentTree segmentTree(n);
    segmentTree.build(nums);
 
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l--, r--;
            segmentTree.add(l, r + 1, v);
        } else {
            int i;
            cin >> i;
            i--;
            cout << segmentTree.get(i) << '\n';
        }
    }
}