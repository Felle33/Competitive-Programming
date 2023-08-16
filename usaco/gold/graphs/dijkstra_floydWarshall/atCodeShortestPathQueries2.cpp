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
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> dis(n, vector<ll>(n, INF));
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--,b--;
        dis[a][b] = c;
    }

    rep(i, n) {
        dis[i][i] = 0;
    }

    ll ans = 0;
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dis[i][k] != INF && dis[k][j] != INF) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dis[i][j] != INF) {
                    ans += dis[i][j];
                }
            }
        }
    }

    cout << ans << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}