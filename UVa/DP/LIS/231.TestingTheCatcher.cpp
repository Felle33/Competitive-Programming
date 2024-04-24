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

int findIndex(vector<int>& lis, int num) {
    int l = -1, r = lis.size();

    while(l + 1 < r) {
        int m = l + (r - l) / 2;

        if(lis[m] >= num) l = m;
        else r = m;
    }

    return r;
}

void solve(){
    int t = 0;
    while(1) {
        int num; cin >> num;

        if(num < 0) return;

        vi missiles;
        while(num >= 0) {
            missiles.pb(num);
            cin >> num;
        }

        vi lis;

        for(int x : missiles) {
            if(lis.empty() || lis.back() >= x) lis.pb(x);
            else {
                lis[findIndex(lis, x)] = x;
            }
        }

        if(t > 0) cout << "\n";
        cout << "Test #" << t + 1 << ":\n  maximum possible interceptions: " << lis.size() << "\n";
        t++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);

    solve();
}