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
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    if(n == 1) {
        cout << 1 << '\n';
        return;
    }

    vi b;
    int x = a[0];
    b.push_back(x);
    for(int l = 1; l < n; l++) {
        if(a[l] != x) {
            b.push_back(a[l]);
            x = a[l];
        }
    }

    int m = b.size();
    if(m <= 2) {
        cout << m << '\n';
        return;
    }

    bool asc = (b[1] - b[0]) > 0;
    int ans = 2;
    for(int i = 2; i < m; i++) {
        if(asc && b[i] - b[i - 1] < 0) {
            asc = false;
            ans++;
        } else if(!asc && b[i] - b[i - 1] > 0) {
            asc = true;
            ans++;
        }
    }

    cout << ans << '\n';
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