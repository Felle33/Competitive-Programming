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
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int ord(char c) {
    return c - 'a' + 1;
}

void solve(){
    string s; cin >> s;
    int n = s.size();

    ll b = 37;
    vll hash(n + 1);
    vll pows(n);
    pows[0] = 1;
    for(int i = 1; i < n; i++) pows[i] = pows[i - 1] * b % MOD1;

    for(int i = 0; i < n; i++) {
        hash[i + 1] = (hash[i] * b + ord(s[i])) % MOD1;
    }

    vector<pair<ll, ll>> t;
    for(int len = 1; len <= n - 1; len++) {
        ll pref = hash[len];
        ll suf = hash[n] - (hash[n - len] * pows[len] % MOD1);

        if(suf < 0) suf += MOD1;

        if(suf == pref) {
            t.pb(mp(suf, len));
        }
    }

    int m = t.size();
    int l = -1, r = m;

    auto good = [&](int mid) -> bool {
        // check if there is a substr in the middle of the string
        ll hash_to_check = t[mid].first;
        ll len = t[mid].second;

        for(int l = 1, r = 1 + len; r <= n - 1; ) {
            ll in_hash = hash[r] - hash[l] * pows[len] % MOD1;
            if(in_hash < 0) in_hash += MOD1;

            if(in_hash == hash_to_check) return 1;
            r++, l++;
        }

        return 0;
    };

    while(l + 1 < r) {
        int mid = l + (r - l) / 2;

        if(good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    if(l == -1) {
        cout << "Just a legend\n";
    } else {
        int len = t[l].second;
        cout << s.substr(0, len) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}