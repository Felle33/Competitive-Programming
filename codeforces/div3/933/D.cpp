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
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, m, x; cin >> n >> m >> x;

    x--;
    set<int> curSet;
    curSet.insert(x);

    rep(i, m) {
        set<int> nextSet;
        int f;
        char c;
        cin >> f >> c;

        for(int el : curSet) {
            if(c == '0') {
                nextSet.insert((el + f) % n);
            } else if(c == '1') {
                int nextOne = el - f;
                nextSet.insert(nextOne < 0 ? nextOne + n : nextOne);
            } else {
                nextSet.insert((el + f) % n);
                int nextOne = el - f;
                nextSet.insert(nextOne < 0 ? nextOne + n : nextOne);
            }
        }
        
        curSet = nextSet;
    }

    cout << curSet.size() << '\n';
    for(int el : curSet) {
        cout << el + 1 << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}