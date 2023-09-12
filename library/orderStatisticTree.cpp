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
            if(tree[x] == 0) {
                tree[x] = 1;
                elementsPresent++;
            }
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

    void erase(int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(tree[x] == 1) {
                tree[x] = 0;
                elementsPresent--;
            }
            return;
        }

        int mid = (lx + rx) / 2;
        if(v < mid) {
            erase(v, 2 * x + 1, lx, mid);
        } else {
            erase(v, 2 * x + 2, mid, rx);
        }

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void erase(int v) {
        erase(v, 0, 0, lastLevelSize);
    }

    bool present(int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            return tree[x];
        }

        int mid = (lx + rx) / 2;
        if(v < mid) return present(v, 2 * x + 1, lx, mid);
        
        return present(v, 2 * x + 2, mid, rx);
    }

    bool present(int v) {
        return present(v, 0, 0, lastLevelSize);
    }

    int order_of_key(int v, int x, int lx, int rx) {
        if(rx - lx == 1) return 0;
        int mid = (lx + rx) / 2;

        if(v < mid) {
            return order_of_key(v, 2 * x + 1, lx, mid);
        }
        return tree[2 * x + 1] + order_of_key(v, 2 * x + 2, mid, rx);
    }

    int order_of_key(int v) {
        if(v >= lastLevelSize) return tree[0];
        return order_of_key(v, 0, 0, lastLevelSize);
    }

    int find_by_order(int k, int x, int lx, int rx) {
        if(rx - lx == 1) {
            return lx;
        }

        int mid = (lx + rx) / 2;
        if(k < tree[2 * x + 1]) return find_by_order(k, 2 * x + 1, lx, mid);
        return find_by_order(k - tree[2 * x + 1], 2 * x + 2, mid, rx);
    }

    int find_by_order(int k) {
        if(k >= tree[0]) return -1;
        return find_by_order(k, 0, 0, lastLevelSize);
    }

    int size() {
        return elementsPresent;
    }
};

void solve(){
    int n; cin >> n;

    Ordered_statistic_tree ost(8);
    rep(i, n) {
        int op; cin >> op;
        if(op == 1) {
            int v; cin >> v;
            ost.insert(v);
        } else if(op == 2) {
            int v; cin >> v;
            ost.erase(v);
        } else if(op == 3) {
            int v; cin >> v;
            cout << ost.order_of_key(v) << '\n';
        } else if(op == 4) {
            int k; cin >> k;
            cout << ost.find_by_order(k) << '\n';
        }
    }
}

int main(){
    solve();
}