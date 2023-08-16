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
#define f first
#define s second
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";
string chokudai = "chokudai";
int m = chokudai.size();

int rec(int i, string& str, int l, vector<vector<int>>& dp) {
    int n = str.size();
    if(l == m) return 1;
    if(i == n) return 0;
    if(dp[i][l] != -1) return dp[i][l];

    dp[i][l] = rec(i + 1, str, l, dp);
    if(str[i] == chokudai[l]) {
        dp[i][l] = (dp[i][l] + rec(i + 1, str, l + 1, dp)) % MOD;
    }

    return dp[i][l];
}

void solve(){
    string str;
    cin >> str;
    vector<vector<int>> dp(str.size(), vector<int>(m, -1));
    cout << rec(0, str, 0, dp);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}