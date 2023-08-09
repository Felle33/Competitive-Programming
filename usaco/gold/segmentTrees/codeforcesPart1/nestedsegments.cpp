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

    ll calc(int l, int r) {
        return calc(l, r, 0, 0, sizeLastLevel);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<ll> input(2 * n);
    for(int i = 0; i < 2 * n; i++) {
        cin >> input[i];
        input[i]--;
    }

    SegmentTree segmentTree(2 * n);

    // mem the left end of all the numbers
    vector<int> pos(n, -1);
    // mem the nested segment of one number
    vector<ll> res(n);
    for(int i = 0; i < 2 * n; i++) {
        if(pos[input[i]] == -1) {
            pos[input[i]] = i;
        } else {
            res[input[i]] = segmentTree.calc(pos[input[i]], i + 1);
            segmentTree.set(pos[input[i]], 1);
        }
    }

    for(int x : res) {
        cout << x << ' ';
    }
}