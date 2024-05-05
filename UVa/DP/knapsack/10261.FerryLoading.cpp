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

int n;
int w;
vi pref, a;

int rec(int i, int port, vvi& dp, vvi& pos) {
    int spaceStar = w - (pref[i] - (w - port));
    if(i == n) return 0;
    if(dp[i][port] != -1) return dp[i][port];

    int ans = 0;
    if(a[i] <= port) {
        ans = 1 + rec(i + 1, port - a[i], dp, pos);
        pos[i][port] = 0;
    }

    if(a[i] <= spaceStar) {
        int res = 1 + rec(i + 1, port, dp, pos);
        if(res > ans) {
            ans = res;
            pos[i][port] = 1;
        }
    }

    dp[i][port] = ans;
    return dp[i][port];
}

void solve(int t){
    cin >> w;
    w *= 100;
    a.erase(all(a));
    pref.erase(all(pref));
    pref.pb(0);
    while(1) {
        int x; cin >> x;
        if(x == 0) break;
        a.pb(x);
        pref.pb(pref.back() + x);
    }

    n = a.size();

    if(t > 0) cout << '\n';
    if(n == 0) {
        cout << 0 << '\n';
        return;
    }

    vvi dp(n, vi(w + 1, -1));
    vvi pos(n, vi(w + 1, -1));

    cout << rec(0, w, dp, pos) << '\n';

    int port = w;
    int i = 0;
    int to = pos[i][port];
    while(to != -1) {
        if(to == 0) {
            cout << "port\n";
            port -= a[i];
        } else {
            cout << "starboard\n";
        }
        i++;
        if(i >= n) break;
        to = pos[i][port];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);
    int t; cin >> t;
    rep(i, t) solve(i);
}