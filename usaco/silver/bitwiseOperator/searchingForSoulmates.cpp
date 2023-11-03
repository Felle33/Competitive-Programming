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
typedef unsigned long long ull;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int firstBitFromLeft(ull a) {
    for(int i = 63; i >= 0; i--) {
        if(a & (1 << i)) return i;
    }
    return -1;
}

int onesToErase(ull a, int dif) {
    int op = 0;
    for(int i = 0; i < dif; i++) {
        if(a & (1 << i)) op++;
    }
    return op;
}

void solve(){
    ull a, b;
    cin >> a >> b;

    if(a == b) {
        cout << 0 << '\n';
        return;
    }

    if(a < b) swap(a, b);

    int op = 0;
    while(a > b) {
        if(a & 1) op++, a++;
        op++;
        a >>= 1;
    }

    op += b - a;
    cout << op << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t; cin >> t;
    while(t--) {
        solve();
    }
}