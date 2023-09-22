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
    ll NEUTRAL_ELEMENT_OP = 0;

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
    }

    void add(int l_query, int r_query, ll value, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query) {
            tree[x] += value * (r_query - l_query);
            op[x] += value;
            return;
        }

        int mid = (lx + rx) / 2;
        add(l_query, r_query, value, 2 * x + 1, lx, mid);
        add(l_query, r_query, value, 2 * x + 2, mid, rx);
        tree[x] += (tree[2 * x + 1] + tree[2 * x + 2]) ;
    }

    void add(int l, int r, ll v) {
        add(l, r, v, 0, 0, size);
    }

    pair<ll, ll> sum(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return mp(0, 0);
        if(l_query <= lx && rx <= r_query) {
            return mp(tree[x], rx - lx);
        }

        int mid = (lx + rx) / 2;
        pair<ll, ll> s1 = sum(l_query, r_query, 2 * x + 1, lx, mid);
        pair<ll, ll> s2 = sum(l_query, r_query, 2 * x + 2, mid, rx);
        return mp((s1.first + s2.first) + op[x] * (s1.second + s2.second), s1.second + s2.second);
    }

    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size).first;
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
    vll a(n);
    segmentTree.build(a);

    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            segmentTree.add(l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << segmentTree.sum(l, r) << '\n';
        }
    }
}