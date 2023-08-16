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
 
    void addOne(int i, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] += 1;
            return;
        }
 
        int m = (lx + rx) / 2;
        if(i < m) {
            addOne(i, 2 * x + 1, lx, m);
        } else {
            addOne(i, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
 
    void addOne(int i) {
        addOne(i, 0, 0, size);
    }

    void minusOne(int i, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] -= 1;
            return;
        }
 
        int m = (lx + rx) / 2;
        if(i < m) {
            minusOne(i, 2 * x + 1, lx, m);
        } else {
            minusOne(i, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
 
    void minusOne(int i) {
        minusOne(i, 0, 0, size);
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
 
    int n;
    cin >> n;

    vector<ll> nums(n);
    rep(i, n) {
        cin >> nums[i];
    }
 
    SegmentTree left(n + 1), right(n + 1);
    left.addOne(nums[0]);
    
    for(int i = 2; i < n; i++) {
        right.addOne(nums[i]);
    }

    ll ans = 0;
    for(int i = 1; i < n - 1; i++) {
        ll leftMajor = left.sum(nums[i] + 1, n + 1);
        ll rightMinor = right.sum(0, nums[i]);
        ans += leftMajor * rightMinor;
        left.addOne(nums[i]);
        right.minusOne(nums[i + 1]);
    }

    cout << ans << '\n';
}