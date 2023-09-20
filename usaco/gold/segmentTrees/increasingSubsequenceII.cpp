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

int ans = 0;

void add_mod(int& a, int b) {
    a += b;
    if(a >= MOD) a -= MOD;
}

struct Ordered_statistic_tree {
    int lastLevelSize;
    int elementsPresent = 0;
    vector<int> tree;

    ll NEUTRAL_ELEMENT = 0LL;

    Ordered_statistic_tree(int n) {
        lastLevelSize = 1;
        while(lastLevelSize < n) lastLevelSize *= 2;
        tree.resize(2 * lastLevelSize, NEUTRAL_ELEMENT);
    }

    int order_of_key(int v, int x, int lx, int rx) {
        if(rx - lx == 1) return 0;
        int mid = (lx + rx) / 2;

        if(v < mid) {
            return order_of_key(v, 2 * x + 1, lx, mid);
        }
        int res = 0;
        add_mod(res, tree[2 * x + 1] + order_of_key(v, 2 * x + 2, mid, rx));
        return res;
    }

    int order_of_key(int v) {
        if(v >= lastLevelSize) return tree[0];
        return order_of_key(v, 0, 0, lastLevelSize);
    }

    void add(int i, int value, int x, int lx, int rx) {
        if(rx - lx == 1) {
            //int tmp = (value - tree[x] < 0 ? value - tree[x] + MOD : value - tree[x]);
            add_mod(tree[x], value);
            elementsPresent++;
            return;
        }

        int mid = (lx + rx) / 2;
        if(i < mid) {
            add(i, value, 2 * x + 1, lx, mid);
        } else {
            add(i, value, 2 * x + 2, mid, rx);
        }

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        if(tree[x] >= MOD) tree[x] -= MOD;
    }

    void add(int i, int value) {
        add(i, value, 0, 0, lastLevelSize);
    }

    ll size() {
        return elementsPresent;
    }
};

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    map<int, int> comp;
    vi copy = a;
    sort(all(copy));
    int k = 1;
    rep(i, n) if(comp.count(copy[i]) == 0) comp[copy[i]] = k++;

    Ordered_statistic_tree ord(comp.size() + 1);
    
    for(int i = 0; i < n; i++) {
        int num = 1;
        int search = comp[a[i]];
        int tmp = ord.order_of_key(search);
        add_mod(num, tmp);
        ord.add(comp[a[i]], num);
    }

    cout << ord.order_of_key(comp.size() + 2) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("haircut.in", "r", stdin);
	//freopen("haircut.out", "w", stdout);

    solve();
    
}