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
    int sizeLastLevel;
    vector<ll> tree;

    SegmentTree() {}

    SegmentTree(int n) {
        sizeLastLevel = 1;
        while(sizeLastLevel < n) sizeLastLevel *= 2;
        tree.resize(2 * sizeLastLevel, 0);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, sizeLastLevel);
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

    void set(int i, ll v, int x, int lx, int rx) {
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

    void set(int i, ll v) {
        set(i, v, 0, 0, sizeLastLevel);
    }

    ll calc(int l_query, int r_query, int x, int lx, int rx) {
        if(r_query <= lx || l_query >= rx) return 0;
        if(l_query <= lx && rx <= r_query) return tree[x];

        int mid = (lx + rx) / 2;
        ll res1 = calc(l_query, r_query, 2 * x + 1, lx, mid);
        ll res2 = calc(l_query, r_query, 2 * x + 2, mid, rx);
        return res1 + res2;
    }

    // r is exclusive
    ll calc(int l, int r) {
        return calc(l, r, 0, 0, sizeLastLevel);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n;

    vector<ll> nums(n);

    rep(i, n) {
        cin >> nums[i];
    }

    SegmentTree sgtPari(n), sgtDispari(n);

    rep(i, n) {
        if(i % 2 == 1) {
            nums[i] = -nums[i];
        }
    }

    sgtPari.build(nums);
    rep(i, n) {
        nums[i] = -nums[i];
    }
    sgtDispari.build(nums);

    cin >> m;
    while(m--) {
        int op;
        cin >> op;
        
        if(op == 0) {
            int i, j;
            cin >> i >> j;
            i--;
            if(i % 2 == 0) {
                sgtPari.set(i, j);
                sgtDispari.set(i, -j);
            } else {
                sgtPari.set(i, -j);
                sgtDispari.set(i, j);
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            if(l % 2 == 0) {
                cout << sgtPari.calc(l, r) << '\n';
            } else {
                cout << sgtDispari.calc(l, r) << '\n';
            }
        }
    }
    
}