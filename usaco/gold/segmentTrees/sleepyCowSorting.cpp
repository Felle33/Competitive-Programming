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

struct Ordered_statistic_tree {
    int lastLevelSize;
    int elementsPresent = 0;
    vector<ll> tree;

    ll NEUTRAL_ELEMENT = 0LL;

    Ordered_statistic_tree(int n) {
        lastLevelSize = 1;
        while(lastLevelSize < n) lastLevelSize *= 2;
        tree.resize(2 * lastLevelSize, NEUTRAL_ELEMENT);
    }

    void insert(int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = 1;
            elementsPresent++;
            return;
        }

        int mid = (lx + rx) / 2;
        if(v < mid) {
            insert(v, 2 * x + 1, lx, mid);
        } else {
            insert(v, 2 * x + 2, mid, rx);
        }

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void insert(int v) {
        insert(v, 0, 0, lastLevelSize);
    }

    ll order_of_key(int v, int x, int lx, int rx) {
        if(rx - lx == 1) return 0;
        int mid = (lx + rx) / 2;

        if(v < mid) {
            return order_of_key(v, 2 * x + 1, lx, mid);
        }
        return tree[2 * x + 1] + order_of_key(v, 2 * x + 2, mid, rx);
    }

    ll order_of_key(int v) {
        if(v >= lastLevelSize) return tree[0];
        return order_of_key(v, 0, 0, lastLevelSize);
    }

    ll size() {
        return elementsPresent;
    }
};

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    int lim = n - 2;
    for(; a[lim] < a[lim + 1]; lim--);

    cout << (lim + 1) << '\n';

    Ordered_statistic_tree ord(n + 1);
    for(int cur = lim + 1; cur < n; cur++) ord.insert(a[cur]);

    for(int i = 0; lim >= 0; lim--, i++) {
        ll k = ord.order_of_key(a[i]);
        if(lim == 0) {
            cout << k;
        } else {
            cout << (k + lim) << " ";
        }
        ord.insert(a[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);

    solve();
    
}