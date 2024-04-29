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

void solve(int t){
    int n; cin >> n;
    vi a(n - 1);
    rep(i, n - 1) cin >> a[i];

    int ans = 0, ansStart = -1, ansStop = -1;
    int curSum = 0, curStart = 0;
    for(int i = 0; i < n - 1; i++) {
        curSum += a[i];

        if(curSum < 0) {
            curSum = 0;
            curStart = i + 1;
        } else {
            if(ans < curSum) {
                ans = curSum;
                ansStart = curStart;
                ansStop = i;
            } else if(ans == curSum) {
                if(i - curStart > ansStop - ansStart) {
                    ansStart = curStart;
                    ansStop = i;
                }
            }
        }
    }

    if(ans == 0) {
        cout << "Route " << t << " has no nice parts" << '\n';
    } else {
        cout << "The nicest part of route " << t << " is between stops " << ansStart + 1 << " and " << ansStop + 2 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);

    int t;
    cin >> t;

    rep(i, t){
        solve(i + 1);
    }
}