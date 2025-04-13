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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define FELLE ios_base::sync_with_stdio(false); cin.tie(NULL); std::cout.precision(10); cout << std::fixed;

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DI = {0, 1, -1, 0};
vector<int> DJ = {1, 0, 0, -1};

void solve(){
    int n; cin >> n;
    map<int, vector<int>> mp;

    rep(i, n) {
        int x; cin >> x;
        mp[x].push_back(i);
    }

    int q; cin >> q;
    rep(i, q) {
        int l, r, x; cin >> l >> r >> x;
        l--, r--;
        if(mp.count(x) == 0) {
            cout << 0 << "\n";
        } else {
            auto it_left = lower_bound(all(mp[x]), l);
            if(it_left == mp[x].end() || *it_left > r) {
                cout << 0 << "\n";
            } else {
                auto it_right = upper_bound(all(mp[x]), r);
                --it_right;
                cout << (it_right - it_left + 1) << "\n";
            }
        }
    }
}

int main(){
    FELLE
    solve();
}