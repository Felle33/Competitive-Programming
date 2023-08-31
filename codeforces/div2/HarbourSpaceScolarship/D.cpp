#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    rep(i, n) {
        rep(j, n) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> b(n, vi(n)), c(n, vi(n));
    int ans = 0;
    int pref = 0;
    for(int i = 0; i < n; i++) {
        int curOp = 0;
        if(i > 0) {
            pref += b[i - 1][0];
            for(int j = 0; j < n; j++) {
                if(j < n - 1) b[i][j] += b[i - 1][j + 1];
                if(j > 0) c[i][j] += c[i - 1][j - 1];
            }
        }

        int prefNow = pref;

        for(int j = 0; j < n; j++) {
            curOp += b[i][j] + c[i][j];
            int a = grid[i][j] - '0' + curOp + prefNow;

            if(a % 2) {
                ans++;
                if(i < n - 1) {
                    if(j == 0) pref++;
                    if(j > 0) b[i + 1][j - 1]++;
                    if(j < n - 2) c[i + 1][j + 2]--;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}