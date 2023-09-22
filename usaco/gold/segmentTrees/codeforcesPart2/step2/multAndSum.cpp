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
#include <array>

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

struct SegmentTree {
    int size;
    vector<ll> tree;
    vector<ll> op;
 
    ll NEUTRAL_ELEMENT = 0;
    ll NEUTRAL_ELEMENT_OP = 1;
 
    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
        op.resize(2 * size, NEUTRAL_ELEMENT_OP);
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
        if(tree[x] >= MOD) tree[x] -= MOD;
    }
 
    void mul(int l_query, int r_query, ll value, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query) {
            tree[x] *= value;
            tree[x] %= MOD;
            op[x] *= value;
            op[x] %= MOD;
            return;
        }
 
        int mid = (lx + rx) / 2;
        mul(l_query, r_query, value, 2 * x + 1, lx, mid);
        mul(l_query, r_query, value, 2 * x + 2, mid, rx);
        tree[x] = (tree[2 * x + 1] + tree[2 * x + 2]);
        if(tree[x] >= MOD) tree[x] -= MOD;
        tree[x] *= op[x];
        tree[x] %= MOD;
    }
 
    void mul(int l, int r, ll v) {
        mul(l, r, v, 0, 0, size);
    }
 
    ll sum(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) {
            return tree[x];
        }
 
        int mid = (lx + rx) / 2;
        ll s1 = sum(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = sum(l_query, r_query, 2 * x + 2, mid, rx);
        ll tmp = s1 + s2;
        if(tmp >= MOD) tmp -= MOD;
        tmp *= op[x];
        return tmp % MOD;
    }
 
    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;
    int n, m;
    cin >> n >> m;
 
    SegmentTree segmentTree(n);
    vll a(n, 1);
    segmentTree.build(a);
 
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            segmentTree.mul(l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << segmentTree.sum(l, r) << '\n';
        }
    }
}