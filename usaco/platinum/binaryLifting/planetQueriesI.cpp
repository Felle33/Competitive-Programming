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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
const ll MAX_N = 2e5 + 1;
const ll LOG = 30;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int suc[MAX_N][LOG];
int n;

int get_teleport(int x, int k) {
    for(int j = LOG - 1; j >= 0; j--) {
        if(k & (1 << j)) x = suc[x][j];
    }
    return x;
}

void compile_suc() {
    for(int i = 1; i < LOG; i++) {
        for(int node = 0; node < n; node++) {
            suc[node][i] = suc[suc[node][i - 1]][i - 1];
        }
    }
}

void solve(){
    int q; cin >> n >> q;
    rep(i, n) {
        int b;
        cin >> b;
        b--;
        suc[i][0] = b;
    }

    compile_suc();

    rep(i, q) {
        int x, k; cin >> x >> k;
        x--;
        
        cout << get_teleport(x, k) + 1 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}