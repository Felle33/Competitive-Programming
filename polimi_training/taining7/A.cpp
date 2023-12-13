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

int n, m;
string haystack;

ll b = 127;
// hash -> index in strings (1-indexed)
map<int, int> hashes;

ll ord(char c) {
    c = tolower(c);
    return c - 'A' + 1;
}

void compute_rolling_hash(string& s, int index) {
    int k = s.size();
    ll h = 0;

    for(int i = 0; i < k; i++) {
        h = (h * b + ord(s[i])) % MOD1;
    }
    hashes[h] = index;
}

int rec(int start, vi& dp) {
    if(start >= n) return 1;
    if(dp[start] != -1) return dp[start];

    ll h = 0;
    for(int i = start; i < n; i++) {
        h = (h * b + ord(haystack[i])) % MOD1;
        if(hashes.count(h)) {
            int res = rec(i + 1, dp);
            if(res >= 1) {
                dp[start] = hashes[h];
                return 1;
            }
        }
    }

    dp[start] = 0;
    return -1;
}

void solve(){
    cin >> n >> haystack >> m;
    vector<string> strings(m);
    rep(i, m) {
        cin >> strings[i];
        compute_rolling_hash(strings[i], i + 1);
    }

    reverse(all(haystack));

    vector<int> dp(n, -1);
    rec(0, dp);

    vector<int> index_words;

    int index_dp = 0;
    while(index_dp < n) {
        int index_word = dp[index_dp] - 1;
        index_words.pb(index_word);
        index_dp += strings[index_word].size();
    }
    
    reverse(all(index_words));
    string ans = "";
    for(int i = 0; i < (int) index_words.size(); i++) {
        ans += strings[index_words[i]] + (i < n - 1 ? " " : "");
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