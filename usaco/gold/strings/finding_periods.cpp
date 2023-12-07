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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void search(string& haystack, string& needle, ll mod, vi& v) {
    ll b = 31;
    int n = haystack.size();
    int m = needle.size();
    // the last power used in the algo
    ll h = 1;
    ll hash_needle = 0;
    ll hash_hay = 0;

    for(int i = 0; i < m - 1; i++) {
        h = (h * b) % mod;
    }

    for(int i = 0; i < m; i++) {
        hash_needle = (b * hash_needle + needle[i]) % mod;
        hash_hay = (b * hash_hay + haystack[i]) % mod;
    }

    for(int i = 0; i <= n - m; i++) {
        if(hash_needle == hash_hay) {
            v.pb(i);
            cout << "Found an equal substring at index " << i << '\n';
        }

        if(i < n - m) {
            hash_hay = (b * (mod + hash_hay - h * haystack[i]) + haystack[i + m]) % mod;
        }
    }
}

int ord(char c) {
    return c - 'a';
}

void solve(){
    string s; cin >> s;
    int n = s.size();
    ll b = 31;
    ll needle_hash = 0;
    ll hay_hash_initial = 0;
    ll h = 1;

    vll b_pow(n);
    b_pow[0] = 1;
    for(int i = 1; i < n; i++) b_pow[i] = (b_pow[i - 1] * b) % MOD;

    vll pref(n);
    pref[0] = ord(s[0]);
    for(int i = 1; i < n; i++) pref[i] = (pref[i - 1] * b + ord(s[i])) % MOD;

    auto calc_hash = [&](int l, int r) -> ll {
        ll h = pref[r - 1] - (l - 1 < 0 ? 0 : (pref[l - 1] * b_pow[r - l]) % MOD);
        return h < 0 ? h + MOD : h;
    };

    for(int i = 0; i < n; i++) {
        // len = pref length
        int len = i + 1;
        bool ok = 1;

        for(int cur_idx = 0; cur_idx < n;) {
            int len_to_compare = min(len, n - cur_idx);
            if(calc_hash(0, len_to_compare) != calc_hash(cur_idx, cur_idx + len_to_compare)) {
                ok = 0;
            }
            cur_idx += len_to_compare;
        }

        if(ok) {
            cout << len << ' ';
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}