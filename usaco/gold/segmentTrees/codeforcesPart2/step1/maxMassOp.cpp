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
    vector<int> tree;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, 0);
    }

    void maxi(int l_query, int r_query, int v, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query){
            tree[x] = max(tree[x], v);
            return;
        }

        int mid = (lx + rx) / 2;
        maxi(l_query, r_query, v, 2 * x + 1, lx, mid);
        maxi(l_query, r_query, v, 2 * x + 2, mid, rx);
    }

    void maxi(int l, int r, int v) {
        maxi(l, r, v, 0, 0, size);
    }

    int get(int i, int x, int lx, int rx) {
        if(rx - lx == 1) return tree[x];

        int mid = (lx + rx) / 2;
        int res;
        if(i < mid) {
            res = get(i, 2 * x + 1, lx, mid);
        } else {
            res = get(i, 2 * x + 2, mid, rx);
        }

        return max(res, tree[x]);
    }

    int get(int i) {
        return get(i, 0, 0, size);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    SegmentTree segmentTree(n);
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            segmentTree.maxi(l, r, v);
        } else {
            int i;
            cin >> i;
            cout << segmentTree.get(i) << '\n';
        }
    }
}