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
    int n, m; cin >> n >> m;

    vector<vector<ll>> grid(n, vll(m));
    rep(i, n) {
        rep(j, m) cin >> grid[i][j];
    }

    vll heights(m, 1);
    for(int i = 0; i < n; i++) {

        if(i > 0) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == grid[i - 1][j]) {
                    heights[j]++;
                }
            }
        }

        // stack: first position number, second position index
        stack<pair<ll, ll>> st;

        for(int j = 0; j < m; j++) {
            while(!st.empty() && st.top().first > grid[i][j]) {
                pair<ll, ll> p = st.top();
                st.pop();

                // count the valid rectangles
            }
        }
        
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}