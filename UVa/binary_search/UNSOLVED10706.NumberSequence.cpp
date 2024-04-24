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
const int INF = 1e9;
const ll LLINF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<ll> groups;

void solve(){
    ll dig; cin >> dig;
    ll l = 0, r = 1e6;

    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;
        ll sum = mid * (mid + 1) / 2;

        if(dig <= sum) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << (dig - r * (r - 1) / 2) << '\n';
}

int main(){
    int t; cin >> t;

    groups.push_back(1);
    for(ll i = 2; i < INT_MAX; i++) {
        ll digits = 0;

        for(int j = 1; j <= i; j *= 10)
            digits += (i - j + 1);

        groups.push_back(digits + groups[groups.size() - 1]);
    }

    while(t--)
        solve();
}