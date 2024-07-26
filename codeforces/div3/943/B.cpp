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

int n, m;
string s, t; 

bool good(int k) {
    int i = 0;
    for(int j = 0; i < k && j < m; ) {
        if(s[i] == t[j]) {
            i++; j++;
        } else {
            j++;
        }
    }

    return i == k;
}

void solve(){
    cin >> n >> m;
    cin >> s >> t;

    int l = 0, r = min(n, m) + 1;
    while(l + 1 < r) {
        int mid = l + (r - l) / 2;
        if(good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}