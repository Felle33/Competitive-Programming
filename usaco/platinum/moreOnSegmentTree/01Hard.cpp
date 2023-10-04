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

struct Item {
    ll pref1, suf0, len;
};

struct SegmentTree {
    int size;
    vector<Item> tree;

    Item NEUTRAL_ELEMENT = {0, 0, 0};

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x].len = 1;
                if(numbers[lx] == 0) {
                    tree[x].pref1 = 0;
                    tree[x].suf0 = 1;
                } else {
                    tree[x].pref1 = 1;
                    tree[x].suf0 = 0;
                }
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        Item left = tree[2 * x + 1];
        Item right = tree[2 * x + 2];
        tree[x].len = left.len + right.len;
        if(left.suf0 < right.pref1) {
            tree[x].len -= left.suf0 * 2;
            tree[x].suf0 = right.suf0;
            tree[x].pref1 = left.pref1 + right.pref1 - left.suf0;
        } else if(right.pref1 < left.suf0) {
            tree[x].len -= right.pref1 * 2;
            tree[x].suf0 = right.suf0 + left.suf0 - right.pref1;
            tree[x].pref1 = left.pref1;
        } else {
            tree[x].len -= left.suf0 * 2;
            tree[x].suf0 = right.suf0;
            tree[x].pref1 = left.pref1;
        }
    }

    void set(int i, int x, int lx, int rx) {
        if(rx - lx == 1) {
            int v = tree[x].suf0;
            tree[x].len = 1;
            if(v == 0) {
                tree[x].pref1 = 0;
                tree[x].suf0 = 1;
            } else {
                tree[x].pref1 = 1;
                tree[x].suf0 = 0;
            }
            return;
        }

        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, 2 * x + 1, lx, m);
        } else {
            set(i, 2 * x + 2, m, rx);
        }

        Item left = tree[2 * x + 1];
        Item right = tree[2 * x + 2];
        tree[x].len = left.len + right.len;
        if(left.suf0 < right.pref1) {
            tree[x].len -= left.suf0 * 2;
            tree[x].suf0 = right.suf0;
            tree[x].pref1 = left.pref1 + right.pref1 - left.suf0;
        } else if(right.pref1 < left.suf0) {
            tree[x].len -= right.pref1 * 2;
            tree[x].suf0 = right.suf0 + left.suf0 - right.pref1;
            tree[x].pref1 = left.pref1;
        } else {
            tree[x].len -= left.suf0 * 2;
            tree[x].suf0 = right.suf0;
            tree[x].pref1 = left.pref1;
        }
    }

    void set(int i) {
        set(i, 0, 0, size);
    }

    Item len(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        Item res;
        Item left = len(l_query, r_query, 2 * x + 1, lx, mid);
        Item right = len(l_query, r_query, 2 * x + 2, mid, rx);
        
        res.len = left.len + right.len;
        if(left.suf0 < right.pref1) {
            res.len -= left.suf0 * 2;
            res.suf0 = right.suf0;
            res.pref1 = left.pref1 + right.pref1 - left.suf0;
        } else if(right.pref1 < left.suf0) {
            res.len -= right.pref1 * 2;
            res.suf0 = right.suf0 + left.suf0 - right.pref1;
            res.pref1 = left.pref1;
        } else {
            res.len -= left.suf0 * 2;
            res.suf0 = right.suf0;
            res.pref1 = left.pref1;
        }
        return res;
    }

    ll len(int l, int r) {
        return len(l, r, 0, 0, size).len;
    }
};

void solve(){
    string s; cin >> s;
    int q; cin >> q;
    int n = s.size();
    vll nums(n);
    rep(i, n) {
        if(s[i] == '1') {
            nums[i] = 1;
        }
    }
    SegmentTree sgt(n);
    sgt.build(nums);
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int i; cin >> i;
            i--;
            sgt.set(i);
        } else {
            int l, r; cin >> l >> r;
            l--;
            cout << sgt.len(l, r) << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}