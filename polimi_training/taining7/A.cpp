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
#include <unordered_map>

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

const int MAX_N = 10000;

int n, m;
string haystack;
 
ll b = 37;
// hash -> index in strings (1-indexed)
unordered_map<int, int> hashes;
 
// pref for the haystack
vector<ll> prefs(MAX_N + 1);
vector<ll> pows(MAX_N + 1);
vector<string> strings(MAX_N);
vector<int> dp(MAX_N + 1, -1);
 
ll ord(char c) {
    c = tolower(c);
    return c - 'a' + 1;
}
 
void compute_rolling_hash_strings(string& s, int index) {
    int k = s.size();
    ll h = 0;
 
    for(int i = 0; i < k; i++) {
        h = (h * b + ord(s[i])) % MOD1;
    }
    hashes[h] = index;
}
 
void compute_rolling_hash_haystack(string& haystack) {
    prefs[0] = 0;
    pows[0] = 1;
 
    for(int i = 0; i < n; i++) {
        pows[i + 1] = pows[i] * b % MOD1;
        prefs[i + 1] = (prefs[i] * b + ord(haystack[i])) % MOD1;
    }
}

void print(vi& dp, int state) {
    if(state >= n) return;
    print(dp, state + (int)strings[dp[state] - 1].size());
    if(state == 0) {
        cout << strings[dp[state] - 1] << '\n';
    } else {
        cout << strings[dp[state] - 1] << ' ';
    }
}
 
void solve(){
    cin >> n >> haystack >> m;
    rep(i, m) {
        cin >> strings[i];
        compute_rolling_hash_strings(strings[i], i + 1);
    }
 
    reverse(all(haystack));
 
    //compute_rolling_hash_haystack(haystack);
 
    
    // vector that contains the indexes in the haystack
    // from which I deciphered a word
    // vector<int> index_deciphered;
    // I deciphered nothing!
    // index_deciphered.pb(n);
 
    for(int start = n - 1; start >= 0; start--) {
        ll h = 0;
        for(int i = start; i < min(n, i + 1001); i++) {
            h = (h * b + ord(haystack[i])) % MOD1;
            if(hashes.count(h)) {
                // hash of all the haystack from i to n - 1
                if(i == n - 1 || dp[i + 1] != -1) {
                    dp[start] = hashes[h];
                }
            }
        }
    }

    print(dp, 0);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;
 
    solve();
}