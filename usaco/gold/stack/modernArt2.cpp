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
#include <stack>

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

void solve(){
    int n; cin >> n;
    vector<int> start(n + 1, INF), end(n + 1, -1), colors(n + 1);

    for(int i = 1; i <= n; i++) {
        int col; cin >> col;
        colors[i] = col;
        start[col] = min(start[col], i);
        end[col] = max(end[col], i);
    }

    stack<int> st;
    int ans = 0;
    start[0] = 0;
    end[0] = n + 1;
    for(int i = 0; i <= n; i++) {
        int col = colors[i];

        if(i == start[col]) {
            st.push(col);
            ans = max(ans, (int)st.size());
        }

        if(col != st.top()) {
            cout << -1 << '\n';
            return;
        }

        if(i == end[col]) {
            st.pop();
        }
    }

    cout << ans - 1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    freopen("art2.in", "r", stdin);
	freopen("art2.out", "w", stdout);
    solve();
}