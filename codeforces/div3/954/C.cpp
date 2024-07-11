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
    int n, m; cin >> n >> m;
    string s, t; cin >> s;
    
    vi a(m);
    rep(i, m) cin >> a[i];
    cin >> t;

    sort(all(a));
    sort(all(t));
    vector<char> ans;

    for(int la = 0, ra = 0, lt = 0, rt = (int)t.size() - 1; ra < m ; ) {
        while(ra < m && a[la] == a[ra]) ra++;
        for(int j = la; j < ra - 1; j++) ans.pb(t[rt--]);
        ans.pb(t[lt++]);

        la = ra;
    }

    for(int i = 0; i < m; i++) {
        s[a[i] - 1] = ans[i];
    }

    cout << s << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}