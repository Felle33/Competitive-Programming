#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
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

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
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

bool cmp(pii& a, pii& b) {
    return a.first > b.first;
}

void solve(){
    int n; cin >> n;
    vector<pii> coord(n);
    vi elements;
    map<int, int> el_key;

    rep(i, n) {
        cin >> coord[i].first >> coord[i].second;
        elements.push_back(coord[i].first);
        elements.push_back(coord[i].second);
    }

    sort(all(elements));
    int k = 1;
    for(int x : elements) {
        el_key[x] = k++;
    }

    sort(all(coord), cmp);
    set<int> finish;
    Ordered_statistic_tree ord(2 * n + 2);
    ll tot = 0;
    ll ans = 0;

    for(pii& p : coord) {
        ans += ord.order_of_key(el_key[p.second]) - ord.order_of_key(el_key[p.first]);
        ord.insert(el_key[p.second]);
        tot++;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}