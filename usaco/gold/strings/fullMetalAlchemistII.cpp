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

int n;
vector<vector<ll>> prefs;
vll b_pows;
vector<string> strings;
vvi common_length_vector;

ll b = 31;

int ord(char c) {
    return c - 'a' + 1;
}

void calc_hash(string& s, int index) {
    int n = s.size();

    for(int i = 0; i < n; i++) {
        prefs[index][i + 1] = (b * prefs[index][i] + ord(s[i])) % MOD;
    }
}

// idx1 => suf
// idx2 => pref
int length_common(int idx1, int idx2) {
    int ans = 0;
    int len_suf = strings[idx1].size();
    int len_pref = strings[idx2].size();
    int len = min(len_pref, len_suf);
    

    for(int i = 1; i <= len; i++) {
        ll hash_pref = prefs[idx2][i];

        ll hash_suf = prefs[idx1][len_suf] - (prefs[idx1][len_suf - i] * b_pows[i] % MOD);
        if(hash_suf < 0) hash_suf += MOD;

        if(hash_pref == hash_suf) ans = i;
    }

    return ans;
}

ll start_ex(int last_string_index, vector<bool>& used, int string_rem) {
    if(string_rem == 0) return 0;

    ll mi = INF;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            // calculate the common letters
            int len = common_length_vector[last_string_index][i];
            int len_suc = strings[i].size();
            used[i] = 1;
            mi = min(mi, len_suc - len + start_ex(i, used, string_rem - 1));
            used[i] = 0;
        }
    }

    return mi;
}

void solve(){
    cin >> n;
    strings = vector<string>(n);

    rep(i, n) cin >> strings[i];

    int max_len = strings[0].size();

    for(string& s : strings) max_len = max(max_len, (int)s.size());

    common_length_vector = vvi(n, vi(n));
    prefs = vector<vector<ll>>(n, vll(max_len + 1));
    b_pows = vll(max_len);
    b_pows[0] = 1;
    for(int i = 1; i < max_len; i++) b_pows[i] = (b_pows[i - 1] * b) % MOD;

    for(int i = 0; i < n; i++) {
        calc_hash(strings[i], i);
    }

    // PREPROCESSING ALL PARIS OF STRINGS TO CALCULATE THE COMMON PREFIX-SUFFIX !!!!
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            common_length_vector[i][j] = length_common(i, j);
        }
    }

    ll ans = INF;
    vector<bool> used(n);
    for(int i = 0; i < n; i++) {
        used[i] = 1;
        ans = min(ans, (ll)strings[i].size() + start_ex(i, used, n - 1));
        used[i] = 0;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}