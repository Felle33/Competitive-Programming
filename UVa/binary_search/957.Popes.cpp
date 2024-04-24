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

void solve(){
    ll years, n;
    while(cin >> years >> n) {
        vll popes(n);
        rep(i, n) cin >> popes[i];

        vll ans(3);
        for(int i = 0; i < n; i++) {
            auto it = upper_bound(popes.begin(), popes.end(), popes[i] + years - 1);
            ll pop = it - popes.begin();
            ll newAns = pop - i;
            if(newAns > ans[0]) {
                ans[0] = newAns;
                ans[1] = popes[i];
                it--;
                ans[2] = *it;
            }
        }

        cout << ans[0] << " " << ans[1] << " " << ans[2] << '\n';
    }
    
}

int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;*/

    solve();
}