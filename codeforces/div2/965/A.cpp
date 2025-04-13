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
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DI = {0, 1, -1, 0};
vector<int> DJ = {1, 0, 0, -1};

void solve(){
    int xc, yc, k; cin >> xc >> yc >> k;

    vector<pair<int, int>> res;
    if(k % 2 == 1) {
        k--;
        res.push_back({xc, yc});
    }

    for(int i = 1, num = k; num > 0; num -= 2, i++) {
        res.push_back({xc + i, yc});
        res.push_back({xc - i, yc});
    }

    for(pii& p : res) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}