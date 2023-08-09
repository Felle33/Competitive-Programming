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

struct node {
    ll inversions;
    ll numbersInSegment[41];
};

struct SegmentTree {
    int size;
    vector<node> tree;

    node NEUTRAL_ELEMENT = {0, {0}};

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    node merge(node leftSegment, node rightSegment) {
        node res = {leftSegment.inversions + rightSegment.inversions, {0}};

        ll sum = 0;
        for(int i = 1; i <= 40; i++) {
            res.inversions += sum * leftSegment.numbersInSegment[i];
            res.numbersInSegment[i] = leftSegment.numbersInSegment[i] + rightSegment.numbersInSegment[i];
            sum += rightSegment.numbersInSegment[i];
        }

        return res;
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x].inversions = 0;
                tree[x].numbersInSegment[numbers[lx]] = 1;
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            for(int i = 1; i <= 41; i++) {
                if(tree[x].numbersInSegment[i] != 0) {
                    tree[x].numbersInSegment[i] = 0;
                    break;
                }
            }
            
            tree[x].numbersInSegment[v] = 1;
            return;
        }

        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    // i = index of the array in the last row starting from 0 to size - 1
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    node sum(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        node s1 = sum(l_query, r_query, 2 * x + 1, lx, mid);
        node s2 = sum(l_query, r_query, 2 * x + 2, mid, rx);
        return merge(s1, s2);
    }

    node sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    SegmentTree segmentTree(n);
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    segmentTree.build(nums);
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r;
            cin >> l >> r;
            l--;
            cout << segmentTree.sum(l, r).inversions << '\n';
        } else {
            int i, v;
            cin >> i >> v;
            i--;
            segmentTree.set(i, v);
        }
    }
}