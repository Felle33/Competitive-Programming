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
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;

int a[2], b[2];

int simulate(int firsta, int firstb) {
    int winsa = 0, winsb = 0;
    if(a[firsta] > b[firstb]) {
        winsa++;
    } else if(a[firsta] < b[firstb]) {
        winsb++;
    }

    if(a[!firsta] > b[!firstb]) {
        winsa++;
    } else if(a[!firsta] < b[!firstb]) {
        winsb++;
    }

    return winsa > winsb;
}

void solve(){
    cin >> a[0] >> a[1] >> b[0] >> b[1];

    int ans = 0;
    ans += simulate(0, 0);
    ans += simulate(0, 1);
    ans += simulate(1, 0);
    ans += simulate(1, 1);

    cout << ans << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}