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

int n;
string s;
vector<int> dp;

bool vow(char c) {
    return c == 'a' || c == 'e';
}

bool cons(char c ) {
    return c == 'b' || c == 'c' || c == 'd';
}

bool f(int i) {
    if(i >= n) return true;
    if(vow(s[i])) return false;
    if(dp[i] != -1) return 1;

    bool cur = 0;
    if(i < n - 1 && vow(s[i + 1])) {
        bool res = f(i + 2);
        if(res) {
            cur = 1;
            dp[i] = i + 2;
        }
    }

    if(i < n - 2 && vow(s[i + 1]) && cons(s[i + 2])) {
        bool res = f(i + 3);
        if(res) {
            cur = 1;
            dp[i] = i + 3;
        }
    }

    return cur;
}

void solve(){
    cin >> n;
    cin >> s;

    dp = vi(n, -1);

    f(0);

    string ans = "";
    for(int i = 0, k = 0; i < n; ) {
        if(dp[k] == i) {
            ans += '.';
            k = dp[k];
        } else {
            ans += s[i];
            i++;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}