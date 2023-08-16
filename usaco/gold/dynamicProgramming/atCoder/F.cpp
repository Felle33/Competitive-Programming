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
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int>(m));

    if(s[0] == t[0]) {
        dp[0][0] = 1;
    } else {
        dp[0][0] = 0;
    }

    for(int i = 1; i < m; i++) {
        if(s[0] == t[i]) {
            dp[0][i] = 1;
        } else {
            dp[0][i] = dp[0][i - 1];
        }
    }

    for(int i = 1; i < n; i++) {
        if(s[i] == t[0]) {
            dp[i][0] = 1;
        } else {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(s[i] == t[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                if(dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    string res = "";
    int i = n - 1, j = m - 1;
    while(i >= 0 && j >= 0) {
        if(s[i] == t[j]) {
            res.push_back(s[i]);
            i--, j--;
        } else {
            if(i == 0 || j == 0) {
                if(i == 0) j--;
                else i--;
            } else {
                if(dp[i - 1][j] >= dp[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }
    }

    reverse(all(res));
    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}