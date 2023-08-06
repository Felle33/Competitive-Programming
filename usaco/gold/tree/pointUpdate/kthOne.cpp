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
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set(int i, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = !tree[x];
            return;
        }

        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, 2 * x + 1, lx, m);
        } else {
            set(i, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set(int i) {
        set(i, 0, 0, sizeLastLevel);
    }

    int calc(int k, int x, int lx, int rx) {
        if(rx - lx == 1) return x;
        int mid = (lx + rx) / 2;
        if(k < tree[2 * x + 1]) return calc(k, 2 * x + 1, lx, mid);
        return calc(k - tree[2 * x + 1], 2 * x + 2, mid, rx);
    }

    int calc(int k) {
        return calc(k, 0, 0, sizeLastLevel);
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
        int op, i;
        cin >> op >> i;

        if(op == 1) {
            segmentTree.set(i);
        } else {
            cout << (segmentTree.calc(i) + 1 - segmentTree.sizeLastLevel) << '\n';
        }
        
    }
}