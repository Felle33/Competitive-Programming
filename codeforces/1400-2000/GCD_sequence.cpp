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

int n;

void fill_vec(vi& a, vi& b, int idx) {
    for(int i = 0, j = 0; i < n; i++) {
        if(i == idx) continue;
        b[j++] = a[i];
    }
}

bool check_gcd(vi& a) {
    int n = a.size();
    int lastGcd = __gcd(a[0], a[1]);
    for(int i = 2; i < n; i++) {
        int newGcd = __gcd(a[i - 1], a[i]);
        if(newGcd < lastGcd) {
            return false;
        } else lastGcd = newGcd;
    }
    return true;
}

void solve(){
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    // GCD with first and second
    // GCD with first and not second
    // GCD without first

    bool ok = true;
    int idxWrong;
    int lastGcd = __gcd(a[0], a[1]);
    for(int i = 2; i < n; i++) {
        int newGcd = __gcd(a[i - 1], a[i]);
        if(newGcd < lastGcd) {
            ok = false;
            idxWrong = i - 1;
        } 
        lastGcd = newGcd;
    }

    if(ok) {
        cout << "YES\n";
        return;
    }

    vi b(n - 1), c(n - 1), d(n - 1);
    fill_vec(a, b, idxWrong - 1);
    fill_vec(a, c, idxWrong);
    fill_vec(a, d, idxWrong + 1);

    if(check_gcd(b) || check_gcd(c) || check_gcd(d)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}