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

int n;
vi a;

void solve(){
    cin >> n;
    a = vi(n);
    rep(i, n) cin >> a[i];
    vi b;
    b.push_back(a[0]);
    for(int i = 1; i < n; i++) {
        if(a[i] >= a[i - 1]) b.push_back(a[i]);
        else {
            b.push_back(a[i]);
            b.push_back(a[i]);
        }
    }

    int m = b.size();
    cout << m << '\n';
    for(int i = 0; i < m; i++) {
        cout << b[i] << ' ';
    }

    cout << '\n';
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