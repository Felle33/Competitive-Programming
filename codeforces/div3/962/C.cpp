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
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
const int LETTERS = 26;

void solve(){
    int n, q; cin >> n >> q;
    string s, t; cin >> s >> t;
    vvi prefs(n + 1, vi(LETTERS)), preft(n + 1, vi(LETTERS));

    for(int i = 0; i < n; i++) {
        prefs[i + 1] = prefs[i];
        prefs[i + 1][s[i] - 'a']++;
    }

    for(int i = 0; i < n; i++) {
        preft[i + 1] = preft[i];
        preft[i + 1][t[i] - 'a']++;
    }

    vi a(LETTERS), b(LETTERS);
    rep(i, q) {
        int l, r; cin >> l >> r;
        int diff = 0;


        for(int i = 0; i < LETTERS; i++) {
            a[i] = prefs[r][i] - prefs[l - 1][i];
            b[i] = preft[r][i] - preft[l - 1][i];
        }

        for(int i = 0; i < LETTERS; i++) {
            diff += abs(a[i] - b[i]);
        }

        cout << diff / 2 << "\n";
        fill(all(a), 0);
        fill(all(b), 0);
    }
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}