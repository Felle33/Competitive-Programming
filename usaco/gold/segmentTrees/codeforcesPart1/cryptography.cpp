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

ll r;

struct matrix {
    ll a11, a12, a21, a22;
};

matrix product(matrix A, matrix B) {
    return {
        ((A.a11 * B.a11) % r + (A.a12 * B.a21) % r) % r,
        ((A.a11 * B.a12) % r + (A.a12 * B.a22) % r) % r,
        ((A.a21 * B.a11) % r + (A.a22 * B.a21) % r) % r,
        ((A.a21 * B.a12) % r + (A.a22 * B.a22) % r) % r
    };
}

struct SegmentTree {
    int sizeLastLevel;
    vector<matrix> tree;

    matrix NEUTRAL_ELEMENT = {1, 0, 0, 1};

    SegmentTree() {}

    SegmentTree(int n) {
        sizeLastLevel = 1;
        while(sizeLastLevel < n) sizeLastLevel *= 2;
        tree.resize(2 * sizeLastLevel, NEUTRAL_ELEMENT);
    }

    void build(vector<matrix>& numbers){
        build(numbers, 0, 0, sizeLastLevel);
    }

    void build(vector<matrix>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x] = numbers[lx];
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        tree[x] = product(tree[2 * x + 1], tree[2 * x + 2]);
    }

    matrix calc(int l_query, int r_query, int x, int lx, int rx) {
        if(r_query <= lx || l_query >= rx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];

        int mid = (lx + rx) / 2;
        matrix res1 = calc(l_query, r_query, 2 * x + 1, lx, mid);
        matrix res2 = calc(l_query, r_query, 2 * x + 2, mid, rx);
        return product(res1, res2);
    }

    // r is exclusive
    matrix calc(int l, int r) {
        return calc(l, r, 0, 0, sizeLastLevel);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> r >> n >> m;

    vector<matrix> nums(n);

    rep(i, n) {
        cin >> nums[i].a11 >> nums[i].a12 >> nums[i].a21 >> nums[i].a22;
        nums[i].a11 %= r, nums[i].a12 %= r, nums[i].a21 %= r, nums[i].a22 %= r;
    }
    
    SegmentTree sgt(n);
    sgt.build(nums);

    while(m--) {
        int l, r;
        cin >> l >> r;
        l--;
        matrix res = sgt.calc(l, r);
        cout << res.a11 << " " << res.a12 << '\n' << res.a21 << " " << res.a22 << "\n\n";
    }
}