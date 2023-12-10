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

const ll MOD1 = 99999999999999997;
const ll MOD2 = 998244353;
const ll DIM = 1e6;
const ll INF = 1e15;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int ord(char c) {
    return c - 'a' + 1;
}

void solve(){
    string s; cin >> s;
    int q; cin >> q;

    ll b = 137;
    int n = s.size();
    vll hash(n + 1);

    vll pows(n);
    pows[0] = 1;
    for(int i = 1; i < n; i++) pows[i] = (pows[i - 1] * b) % MOD1;

    for(int i = 0; i < n; i++) {
        hash[i + 1] = (hash[i] * b + ord(s[i])) % MOD1;
    }

    while(q--) {
        int l, r; cin >> l >> r;

        ll ans = hash[r] - ((hash[l] * pows[r - l]) % MOD1);
        if(ans < 0) ans += MOD1;
        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}