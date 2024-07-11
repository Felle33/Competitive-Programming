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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

void solve(){
    int n; cin >> n;
    string s, t;
    cin >> s >> t;

    string s_prime(s), t_prime(t);
    for(int i = 0; i < n - 2; i++) {
        if(s[i] == '0' && s[i + 2] == '0') t_prime[i + 1] = '1';
    }

    for(int i = 0; i < n - 2; i++) {
        if(t_prime[i] == '1' && t_prime[i + 2] == '1') s_prime[i + 1] = '1';
    }

    vi a(n + 1);

    for(int i = 0; i < n; i++) a[i + 1] = a[i] + (s_prime[i] == '1');

    int q; cin >> q;

    rep(k, q) {
        int l, r; cin >> l >> r;
        l--, r--;

        if(r - l + 1 <= 5) {
            int ans = 0;
            int m = r - l + 1;
            string sim1(s.substr(l, r - l + 1)), sim2(t.substr(l, r - l + 1));

            for(int i = 0; i < m - 2; i++) {
                if(sim1[i] == '0' && sim1[i + 2] == '0') sim2[i + 1] = '1';
            }

            for(int i = 0; i < m - 2; i++) {
                if(sim2[i] == '1' && sim2[i + 2] == '1') sim1[i + 1] = '1';
            }

            for(char c : sim1) {
                if(c == '1') ans++;
            }

            cout << ans << "\n";
        } else {
            int ans = a[r + 1 - 2] - a[l + 2];

            if(s[l] == '1') ans++;
            if(s[r] == '1') ans++;
            if(s[l + 1] == '1' || (t[l] == '1' && (t[l + 2] == '1' || s[l + 3] == '0'))) ans++;
            if(s[r - 1] == '1' || ((t[r - 2] == '1' || s[r - 3] == '0') && t[r] == '1')) ans++;

            cout << ans << "\n";
        }
    }
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}