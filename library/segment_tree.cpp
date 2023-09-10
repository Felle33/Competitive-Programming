#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>

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
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
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
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
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
            cout << segmentTree.sum(l, r) << '\n';
        }
    }
}