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

struct node {
    set<int> nums;
};

struct SegmentTree {
    int size;
    vector<node> tree;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size);
    }

    void build(vector<int>& numbers){
        build(numbers, 0, 0, size);
    }

    void merge(set<int>& res, set<int>& a, set<int>& b) {
        for (int x : a) res.insert(x);
        for (int x : b) res.insert(x);
    }

    void build(vector<int>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x].nums.insert(numbers[lx]);
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        merge(tree[x].nums, tree[2 * x + 1].nums, tree[2 * x + 2].nums);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    set<int>* more_than(int l_query, int r_query, int x, int lx, int rx, int n) {
        if(l_query >= rx || r_query <= lx) return nullptr;
        if(l_query <= lx && rx <= r_query) return &tree[x].nums;
        int mid = (lx + rx) / 2;
        set<int>* s1 = more_than(l_query, r_query, 2 * x + 1, lx, mid, n);
        set<int>* s2 = more_than(l_query, r_query, 2 * x + 2, mid, rx, n);
        
    }

    ll more_than(int l, int r, int n) {
        return more_than(l, r, 0, 0, size, n)->size();
    }
};

void solve(){
    int n, q; cin >> n >> q;
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
    
}