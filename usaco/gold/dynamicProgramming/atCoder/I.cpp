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

vector<double> prob;
// essendo arrivato al dado i e avendo fatto uscire testa d dadi
// dp[i][d] = probabilità di vincere (ossia d >= n / 2)
vector<vector<double>> dp;
int n;

double win(int i, int d) {
    if(d == (n / 2 + 1)) return 1;
    if(i == n) return 0;
    if(dp[i][d] != -1) return dp[i][d];

    double win_prob = win(i + 1, d + 1) * prob[i] +
                    win(i + 1, d) * ((double)1 - prob[i]);
    dp[i][d] = win_prob;
    return win_prob;
}

void solve(){
    cin >> n;
    prob = vector<double>(n);
    dp = vector<vector<double>>(n, vector<double>(n / 2 + 1, -1));
    rep(i, n) {
        cin >> prob[i];
    }

    cout << win(0, 0) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}