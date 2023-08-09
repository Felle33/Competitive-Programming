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
    vector<int> tree;

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
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
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
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, sizeLastLevel);
    }

    int calc(int v, int j, int x, int lx, int rx) {
        if(v > tree[x] || rx <= j) return -1;
        if(rx - lx == 1) return x;

        int mid = (lx + rx) / 2;
        int res1 = calc(v, j, 2 * x + 1, lx, mid);

        if(res1 != -1) return res1;
        return calc(v, j, 2 * x + 2, mid, rx);
    }

    int calc(int k, int j) {
        int res = calc(k, j, 0, 0, sizeLastLevel);
        return res == -1 ? res : res + 1 - sizeLastLevel;
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<ll> input(n);
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    SegmentTree segmentTree(n);
    segmentTree.build(input);

    while(m--) {
        int op;
        cin >> op;

        if(op == 1) {
            int i, v;
            cin >> i >> v;
            segmentTree.set(i, v);
        } else {
            int v, j;
            cin >> v >> j;
            cout << segmentTree.calc(v, j) << '\n';
        }
        
    }
}