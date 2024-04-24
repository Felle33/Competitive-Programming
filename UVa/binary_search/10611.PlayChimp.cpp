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
const int INF = 1e9;
const ll LLINF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

void solve(){
    int n; cin >> n;
    vll a(n), b(n);
    rep(i, n) {
        cin >> a[i];
        b[i] = -a[i];
    }

    sort(all(b));
    int q; cin >> q;

    rep(i, q) {
        ll h; cin >> h;
        auto it = upper_bound(all(b), -h);
        ll first = it == b.end() ? LLINF : -(*it);
        it = upper_bound(all(a), h);
        ll second = it == a.end() ? LLINF : *it;
        if(first == LLINF) cout << 'X' << " ";
        else cout << first << " ";

        if(second == LLINF) cout << 'X' << '\n';
        else cout << second << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;
    solve();
}