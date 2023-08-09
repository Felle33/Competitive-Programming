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
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }
 
    ll get(int r, int x, int lx, int rx) {
        if(tree[x] < r) return 0;
        if(rx - lx == 1) {
            tree[x] -= r;
            return rx;
        } 
        int mid = (lx + rx) / 2;
        int res;
        if(tree[2 * x + 1] >= r) {
            res = get(r, 2 * x + 1, lx, mid);
        } else {
            res = get(r, 2 * x + 2, mid, rx);
        }

        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
        return res;
    }
 
    ll get(int r) {
        return get(r, 0, 0, size);
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;

    vector<ll> nums(n);
    rep(i, n) {
        cin >> nums[i];
    }
 
    SegmentTree segmentTree(n);
    segmentTree.build(nums);
 
    while(m--) {
        ll r;
        cin >> r;
        cout << segmentTree.get(r) << ' ';
    }
}